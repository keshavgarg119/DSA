# Write your MySQL query statement below
select p.project_id, 
    round(
        coalesce(avg(e.experience_years), 0),
        2
    ) as average_years
from Project p left join Employee E 
on p.employee_id = e.employee_id
group by p.project_id;