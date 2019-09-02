def solution(record):
    log = []
    usr = {}
    answer = []
    for i in range(len(record)):
        cur_msg = record.pop()
        cur_msg = cur_msg.split()

        if cur_msg[0] == 'Change':
            if usr.get(cur_msg[1]) is None:
                usr[cur_msg[1]] = cur_msg[2]

        elif cur_msg[0] == 'Enter':
            log.append('Enter ' + cur_msg[1])
            if usr.get(cur_msg[1]) is None:
                usr[cur_msg[1]] = cur_msg[2]

        else:
            log.append('Leave ' + cur_msg[1])

    for i in range(len(log)):
        log_content = log.pop()
        log_content = log_content.split()

        if log_content[0] == 'Enter':
            answer.append(usr[log_content[1]]+'님이 들어왔습니다.')

        elif log_content[0] == 'Leave':
            answer.append(usr[log_content[1]]+'님이 나갔습니다.')

    return answer
