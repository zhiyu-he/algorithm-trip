#
#
# 176. Second Highest Salary 
# ref: https://leetcode.com/problems/second-highest-salary/
# 
# TIPS: IF EXISTS
#
#

SELECT IF(EXISTS(SELECT DISTINCT Salary FROM `Employee` ORDER BY Salary DESC LIMIT 1, 1), (SELECT distinct Salary FROM `Employee` ORDER BY Salary DESC LIMIT 1, 1), null) AS Salary;

