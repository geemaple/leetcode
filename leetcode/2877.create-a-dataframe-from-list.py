#  Tag: Pandas
#  Time: N/A
#  Space: N/A
#  Ref: -
#  Note: -

#  Write a solution to create a DataFrame from a 2D list called student_data. This 2D list contains the IDs and ages of some students.
#  The DataFrame should have two columns, student_id and age, and be in the same order as the original 2D list.
#  The result format is in the following example.
#   
#  Example 1:
#  
#  Input:
#  student_data:
#  [
#    [1, 15],
#    [2, 11],
#    [3, 11],
#    [4, 20]
#  ]
#  Output:
#  +------------+-----+
#  | student_id | age |
#  +------------+-----+
#  | 1          | 15  |
#  | 2          | 11  |
#  | 3          | 11  |
#  | 4          | 20  |
#  +------------+-----+
#  Explanation:
#  A DataFrame was created on top of student_data, with two columns named student_id and age.
#  
#  

import pandas as pd

def createDataframe(student_data: List[List[int]]) -> pd.DataFrame:
    return pd.DataFrame(student_data, columns=['student_id', 'age'])