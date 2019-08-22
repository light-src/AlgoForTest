# kakao_holiday_traffic


def solution(lines):
    logs, ret = [], 0

    for s in lines:
        end = int(s[11:13])*60*60 + int(s[14:16])*60 + \
            int(s[17:19]) + float('0.'+s[20:23])
        start = round(end - float(s[24:-1]) + 0.001, 3)
        logs.append([start, end])

    for log in logs:
        count = 0
        start, end = log[1], round(log[1]+0.999, 3)
        for others in logs:
            first, last = map(float, others)
            if first <= start and last >= start:
                count += 1
            elif start <= first <= end:
                count += 1

        ret = max(count, ret)
    return ret


if __name__ == "__main__":
    lines = ["2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s"]
    print(solution(lines))
