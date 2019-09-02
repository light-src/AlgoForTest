class Stage:

    def __init__(self, stage):
        self.stage = stage
        self.fail = 0


def solution(N, stages):
    answer = []
    stage_fail = [Stage(i) for i in range(N)]
    success = [0 for _ in range(N)]

    for p in stages:
        going_stage = p-1

        if not going_stage == N:
            stage_fail[going_stage].fail += 1

        for i in range(going_stage):
                success[i] += 1

    for i in range(len(stage_fail)):
        if success[i] != 0:
            stage_fail[i].fail /= success[i]

    stage_fail.sort(key=lambda s: s.fail, reverse=True)

    for s in stage_fail:
        answer.append(s.stage + 1)

    return answer
