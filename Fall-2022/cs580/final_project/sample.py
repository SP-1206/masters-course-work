def evaluation_function(self, state):
        if self.current_move == 1:
            o_color = 2
        elif self.current_move == 2:
            o_color = 1
        my_fours = self.checkForStreak(state, self.current_move, 4)
        my_threes = self.checkForStreak(state, self.current_move, 3)
        my_twos = self.checkForStreak(state, self.current_move, 2)
        comp_fours = self.checkForStreak(state, o_color, 4)
        comp_threes = self.checkForStreak(state, o_color, 3)
        comp_twos = self.checkForStreak(state, o_color, 2)
        return (my_fours * 10 + my_threes * 5 + my_twos * 2) - (comp_fours * 10 + comp_threes * 5 + comp_twos * 2)




    def checkForStreak(self, state, color, streak):
        count = 0
        for i in range(6):
            for j in range(7):
                if state[i][j] == color:
                    count += self.verticalStreak(i, j, state, streak)
                    count += self.horizontalStreak(i, j, state, streak)
                    count += self.diagonalCheck(i, j, state, streak)
        return count

    def verticalStreak(self, row, column, state, streak):
        consecutiveCount = 0
        for i in range(row, 6):
            if state[i][column] == state[row][column]:
                consecutiveCount += 1
            else:
                break
        if consecutiveCount >= streak:
            return 1
        else:
            return 0

    def horizontalStreak(self, row, column, state, streak):
        count = 0
        for j in range(column, 7):
            if state[row][j] == state[row][column]:
                count += 1
            else:
                break
        if count >= streak:
            return 1
        else:
            return 0

    def diagonalCheck(self, row, column, state, streak):
        total = 0
        count = 0
        j = column
        for i in range(row, 6):
            if j > 6:
                break
            elif state[i][j] == state[row][column]:
                count += 1
            else:
                break
            j += 1
        if count >= streak:
            total += 1
        count = 0
        j = column
        for i in range(row, -1, -1):
            if j > 6:
                break
            elif state[i][j] == state[row][column]:
                count += 1
            else:
                break
            j += 1
        if count >= streak:
            total += 1
        return total
