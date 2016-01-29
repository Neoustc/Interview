class Solution(object):
   def isValidSudoku(self,board):
		#rows,columns,squares={},{},{}  three dictionary{ 0: set() ,1 :set()....8: set()};
		rows,columns,squares=({i:set() for i in range(9)}
							for _ in range(3))
		for r in range(9):
			for c in range(9):
				num=board[r][c]
				if num=='.':
					continue
				s=(r/3)*3+c/3
				if num in rows[r] or num in columns[c] or num in squares[s]:
					return False
				rows[r].add(num)
				columns[c].add(num)
				squares[s].add(num)
		return True
