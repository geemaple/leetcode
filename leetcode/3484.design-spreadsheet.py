#  Tag: Array, Hash Table, String, Design, Matrix
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/wEn_77uOqEA

#  A spreadsheet is a grid with 26 columns (labeled from 'A' to 'Z') and a given number of rows. Each cell in the spreadsheet can hold an integer value between 0 and 105.
#  Implement the Spreadsheet class:
#  
#  Spreadsheet(int rows) Initializes a spreadsheet with 26 columns (labeled 'A' to 'Z') and the specified number of rows. All cells are initially set to 0.
#  void setCell(String cell, int value) Sets the value of the specified cell. The cell reference is provided in the format "AX" (e.g., "A1", "B10"), where the letter represents the column (from 'A' to 'Z') and the number represents a 1-indexed row.
#  void resetCell(String cell) Resets the specified cell to 0.
#  int getValue(String formula) Evaluates a formula of the form "=X+Y", where X and Y are either cell references or non-negative integers, and returns the computed sum.
#  
#  Note: If getValue references a cell that has not been explicitly set using setCell, its value is considered 0.
#   
#  Example 1:
#  
#  Input:
#  ["Spreadsheet", "getValue", "setCell", "getValue", "setCell", "getValue", "resetCell", "getValue"]
#  [[3], ["=5+7"], ["A1", 10], ["=A1+6"], ["B2", 15], ["=A1+B2"], ["A1"], ["=A1+B2"]]
#  Output:
#  [null, 12, null, 16, null, 25, null, 15] 
#  Explanation
#  Spreadsheet spreadsheet = new Spreadsheet(3); // Initializes a spreadsheet with 3 rows and 26 columns
#  spreadsheet.getValue("=5+7"); // returns 12 (5+7)
#  spreadsheet.setCell("A1", 10); // sets A1 to 10
#  spreadsheet.getValue("=A1+6"); // returns 16 (10+6)
#  spreadsheet.setCell("B2", 15); // sets B2 to 15
#  spreadsheet.getValue("=A1+B2"); // returns 25 (10+15)
#  spreadsheet.resetCell("A1"); // resets A1 to 0
#  spreadsheet.getValue("=A1+B2"); // returns 15 (0+15)
#   
#  Constraints:
#  
#  1 <= rows <= 103
#  0 <= value <= 105
#  The formula is always in the format "=X+Y", where X and Y are either valid cell references or non-negative integers with values less than or equal to 105.
#  Each cell reference consists of a capital letter from 'A' to 'Z' followed by a row number between 1 and rows.
#  At most 104 calls will be made in total to setCell, resetCell, and getValue.
#  
#  

class Spreadsheet:
    def __init__(self, rows: int):
        self.spread = {}

    def setCell(self, cell: str, value: int) -> None:
        self.spread[cell] = value

    def resetCell(self, cell: str) -> None:
        if cell in self.spread:
            del self.spread[cell]

    def parse(self, cell: str) -> int:
        if cell[0].isalpha():
            return self.spread.get(cell, 0)
        else:
            return int(cell)

    def getValue(self, formula: str) -> int:
        a, b = formula[1:].split('+')
        return self.parse(a) + self.parse(b)

class Spreadsheet:
    def __init__(self, rows: int):
        self.spread = [[0] * 26 for i in range(rows)]

    def setCell(self, cell: str, value: int) -> None:
        j = ord(cell[0]) - ord('A')
        i = int(cell[1:]) - 1
        self.spread[i][j] = value

    def resetCell(self, cell: str) -> None:
        j = ord(cell[0]) - ord('A')
        i = int(cell[1:]) - 1
        self.spread[i][j] = 0   

    def parse(self, cell: str) -> int:
        if cell[0].isalpha():
            j = ord(cell[0]) - ord('A')
            i = int(cell[1:]) - 1 
            return self.spread[i][j]
        else:
            return int(cell)

    def getValue(self, formula: str) -> int:
        a, b = formula[1:].split('+')
        return self.parse(a) + self.parse(b)

# Your Spreadsheet object will be instantiated and called as such:
# obj = Spreadsheet(rows)
# obj.setCell(cell,value)
# obj.resetCell(cell)
# param_3 = obj.getValue(formula)