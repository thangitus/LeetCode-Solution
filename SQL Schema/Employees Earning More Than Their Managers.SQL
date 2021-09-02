/**
  https://leetcode.com/problems/employees-earning-more-than-their-managers/
*/

SELECT Employee.Name AS Employee
FROM Employee,
     Employee as Manager
WHERE Employee.ManagerId = Manager.Id
  AND Employee.Salary > Manager.Salary