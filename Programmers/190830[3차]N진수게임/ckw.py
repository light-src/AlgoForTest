def solution(n, t, m, p):
    answer = ''
    game_content = []
    i = 0
    while True:
        quo = i
        stack = list()

        while True:
            mod = quo % n
            quo = int(quo / n)

            stack.append(mod)

            if quo == 0:
                while True:
                    num = stack.pop()
                    game_content.append(num if num < 10 else chr(ord('A') + num - 10))
                    if len(stack) == 0:
                        break
                break

        i += 1

        if i > t * m :
            break

    for i in range(0, t):
        answer += str(game_content[i*m + p - 1])


    return answer
