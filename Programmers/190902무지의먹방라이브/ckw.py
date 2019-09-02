import copy
import heapq


def solution(food_times, k):

    food_time_lists = copy.deepcopy(food_times)
    heapq.heapify(food_time_lists)

    spent_time = 0
    min_value = food_time_lists[0]
    one_cycle_time = min_value * len(food_time_lists)

    while k >= one_cycle_time:
        k -= one_cycle_time
        spent_time += min_value

        if len(food_time_lists) > 0:
            min_value = food_time_lists[0]
            min_value = min_value - spent_time
            one_cycle_time = min_value * len(food_time_lists)
        else:
            return -1

        heapq.heappop(food_time_lists)

    food_times = [i for i in range(len(food_times)) if food_times[i] - spent_time > 0]
    return food_times[k % len(food_times)] + 1
