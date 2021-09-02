/**
  https://leetcode.com/problems/classes-more-than-5-students/
*/

SELECT Courses.class
FROM Courses
GROUP BY Courses.class
HAVING COUNT(DISTINCT Student) >= 5