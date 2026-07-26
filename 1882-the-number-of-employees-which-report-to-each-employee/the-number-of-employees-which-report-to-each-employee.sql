# Write your MySQL query statement below
select m.employee_id, m.name, count(*) as reports_count, round(avg(e.age), 0) as average_age
from Employees e join Employees m
on e.reports_to = m.employee_id
group by m.employee_id, m.name
order by m.employee_id;