# Write your MySQL query statement below
SELECT Emp.name as Employee
FROM Employee as Emp
INNER JOIN Employee as Mgr
ON Emp.managerId = Mgr.id
WHERE Emp.salary > Mgr.salary;