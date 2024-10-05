

def drawGrid(board):
    for i in range(len(board)):
        for j in range(len(board[0])):
            print(board[i][j], end=' ')
        print()

def drawCircle(board, cx, cy, r):
    x = 0
    y = -r
    while x < -y:
        yMid = y + 0.5
        
        if x*x + yMid*yMid > r*r:
            y = y +1
        
        board[cx+x][cy+y] = 1
        board[cx+x][cy-y] = 1
        board[cx-x][cy+y] = 1
        board[cx-x][cy-y] = 1
        board[cx+y][cy+x] = 1
        board[cx+y][cy-x] = 1
        board[cx-y][cy+x] = 1
        board[cx-y][cy-x] = 1
        x = x + 1
    return
if __name__ == '__main__':
    print('hello, drawCircle')
    board = [[0 for _ in range(30)] for _ in range(30)]
    drawCircle(board, len(board)//2, len(board)//2, len(board)//2-5)
    drawGrid(board)