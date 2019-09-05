available_blocks = [
    [[[0, 0], [1, 0], [2, 0], [2, 1]], [[0, 1], [1, 1]]],
    # [[1, 0],
    #  [1, 0],
    #  [1, 1]],
    [[[0, 0], [1, 0], [2, 0], [2, -1]], [[0, -1], [1, -1]]],
    # [[0, 1],
    #  [0, 1],
    #  [1, 1]],

    [[[0, 0], [1, 0], [1, -1], [1, -2]], [[0, -1], [0, -2]]],
    # [[0, 0, 1],
    #  [1, 1, 1]],
    [[[0, 0], [1, 0], [1, 1], [1, 2]], [[0, 1], [0, 2]]],
    # [[1, 0, 0],
    #  [1, 1, 1]],
    [[[0, 0], [1, 0], [1, -1], [1, 1]], [[0, -1], [0, 1]]]
    # [[0, 1, 0],
    #  [1, 1, 1]]]
]

walls = [False for _ in range(51)]


def can_broken_by(board, num, row, col) -> int:
    for i in range(len(available_blocks)):
        have_to_same = available_blocks[i][0]
        have_to_blank = available_blocks[i][1]

        cnt = 0
        for coord_diff in have_to_same:
            nxt_r = row + coord_diff[0]
            nxt_c = col + coord_diff[1]

            if not (0 <= nxt_r < len(board) and 0 <= nxt_c < len(board[0])):
                break

            if board[nxt_r][nxt_c] != num:
                break

            cnt += 1

        if cnt != 4:
            continue

        cnt = 0
        for coord_diff in have_to_blank:
            nxt_r = row + coord_diff[0]
            nxt_c = col + coord_diff[1]

            if not (0 <= nxt_r < len(board) and 0 <= nxt_c < len(board[0])):
                break

            if board[nxt_r][nxt_c] != 0:
                break

            if walls[nxt_c]:
                break

            cnt += 1

        if cnt == 2:
            return i

    return -1


def break_block(board, row, col, idx):
    for coord_diff in available_blocks[idx][0]:
        nxt_r = row + coord_diff[0]
        nxt_c = col + coord_diff[1]

        board[nxt_r][nxt_c] = 0

def solution(board):
    return solution2(board) + solution2(board) + solution2(board)

def solution2(board):
    answer = 0

    for row in range(len(board)):
        for col in range(len(board)):

            if board[row][col]:
                num = board[row][col]
                can_broken_idx = can_broken_by(board, num, row, col)

                if can_broken_idx != -1:
                    break_block(board, row, col, can_broken_idx)
                    answer += 1
                else:
                    walls[col] = True

    for i in range(len(walls)):
        walls[i] = False

    for row in range(len(board)):
        for col in range(len(board)-1, -1, -1):

            if board[row][col]:
                num = board[row][col]
                can_broken_idx = can_broken_by(board, num, row, col)

                if can_broken_idx != -1:
                    break_block(board, row, col, can_broken_idx)
                    answer += 1
                else:
                    walls[col] = True

    return answer
