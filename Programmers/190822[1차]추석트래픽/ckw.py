from datetime import timedelta
from dateutil.parser import parse


class Task:

    def __init__(self, start, end):
        self.start = start
        self.end = end


def get_time(date_str):

    date, time, duration = date_str.split()
    end_time = parse(date + ' ' + time)
    time_delta = timedelta(seconds=float(duration[:-1])-0.001)
    start_time = end_time - time_delta

    return start_time, end_time


def solution(lines):
    task_list = []
    end_list = []
    
    for l in lines:
        start, end = get_time(l)
        task_list.append(Task(start, end))
        end_list.append(end)

    task_list.sort(key=lambda task:task.start)


    answer = 0

    for end_time in end_list:
        unit_answer = 0
        end_time_plus = end_time + timedelta(seconds=0.999)

        for t in task_list:
            if t.start < end_time:
                if t.end >= end_time:
                    unit_answer += 1

            elif end_time <= t.start <= end_time_plus:
                unit_answer += 1

        answer = unit_answer if answer < unit_answer else answer

    return answer

