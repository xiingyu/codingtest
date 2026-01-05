import csv
import json
import time
from pathlib import Path
from urllib.request import urlopen
from urllib.parse import urlencode


BASE_URL = "https://www.dhlottery.co.kr/common.do"


def fetch_draw(drw_no: int):
    params = urlencode({"method": "getLottoNumber", "drwNo": drw_no})
    url = f"{BASE_URL}?{params}"

    with urlopen(url, timeout=5) as resp:
        data = json.loads(resp.read().decode("utf-8"))

    if data.get("returnValue") != "success":
        return None
    return data


def main():
    out_path = Path(__file__).resolve().parent / "nums.csv"
    rows = []

    drw_no = 1
    fail_count = 0

    while True:
        try:
            data = fetch_draw(drw_no)
        except Exception as e:
            print(f"[WARN] draw {drw_no}: {e}")
            time.sleep(0.5)
            continue

        if data is None:
            fail_count += 1
            if fail_count >= 3:  # 최신 회차 넘겼다고 판단
                break
            continue

        fail_count = 0
        rows.append([
            data["drwNo"],
            data["drwtNo1"],
            data["drwtNo2"],
            data["drwtNo3"],
            data["drwtNo4"],
            data["drwtNo5"],
            data["drwtNo6"],
        ])

        if drw_no % 50 == 0:
            print(f"Fetched up to draw {drw_no}")

        drw_no += 1
        time.sleep(0.03)

    with out_path.open("w", newline="", encoding="utf-8") as f:
        writer = csv.writer(f)
        writer.writerow(["회차", "번호1", "번호2", "번호3", "번호4", "번호5", "번호6"])
        writer.writerows(rows)

    print(f"Saved {len(rows)} rows to {out_path}")


if __name__ == "__main__":
    main()
