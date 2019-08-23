## 아직 90점... 다 안맞네 .ㅠ

from datetime import datetime


def time_parser(start, end):

    start = datetime.strptime(start, "%H:%M")
    end = datetime.strptime(end, "%H:%M")

    return start, end


def get_music_length(content):
    return len(content) - content.count("#")


def get_remain_music(content, remain):
    ret = ""

    for i in range(0, len(content)):
        if content[i] != '#':
            remain -= 1

        ret += content[i]

        if remain == 0:
            if i + 1 != len(content):
                if content[i+1] == '#':
                    ret += content[i+1]

            return ret

    return ret


def get_played_music_string(duration, music_length, content):
    cnt = int(duration / music_length)
    remain = duration % music_length

    return content * cnt + get_remain_music(content, remain)


def get_music_lists(musicinfos):

    music_lists = list()

    for element in musicinfos:
        start_time, end_time, title, content = element.split(',')
        start_time, end_time = time_parser(start_time, end_time)

        duration = end_time - start_time
        duration = int(duration.seconds / 60)

        music_length = get_music_length(content)

        played_music = get_played_music_string(duration, music_length, content)

        music_lists.append([title, played_music, duration])

    return music_lists


def solution(m, musicinfos):

    music_lists = get_music_lists(musicinfos)
    ans_list = list()

    for music_info in music_lists:
        idx = music_info[1].find(m)
        if idx != -1:  # success to find the song
            if idx + len(m) != len(music_info[1]):
                    if music_info[1][idx+len(m)] == '#':  # after the same sentence, # was detected.
                        continue

            ans_list.append([music_info[0], music_info[2]])  # name, duration

    if len(ans_list) == 0:
        return '(None)'

    if len(ans_list) == 1:
        return ans_list[0][0]

    # ans > 1
    ans_list = sorted(ans_list, key=lambda music: music[1], reverse=True)  # sort by duration

    return ans_list[0][0]
