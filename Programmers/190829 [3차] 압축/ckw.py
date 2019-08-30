def solution(msg):
    dictionary = {chr(ord('A')+i): i + 1 for i in range(0, 26)}
    answer = list()

    word = ''
    i = -1
    while True:

        i += 1

        if i >= len(msg):
            break

        word += msg[i]

        if dictionary.get(word) is None and word is not '':
            dictionary[word] = len(dictionary) + 1
            answer.append(dictionary[word[:-1]])
            word = ''
            i -= 1
            continue

        if i == len(msg) - 1:
            answer.append(dictionary[word])

    return answer
