# Write your MySQL query statement below

SELECT e.Name AS Employee  FROM Employee e LEFT JOIN Employee b
       ON e.ManagerId=b.Id
       WHERE e.Salary > b.Salary
