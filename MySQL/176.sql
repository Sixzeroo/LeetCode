# Write your MySQL query statement below
select (select distinct Salary from Employee order by Salary desc limit 1, 1) as SecondHighestSalary;
