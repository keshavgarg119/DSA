select department, employee, salary
from (
    select
        d.name as department,
        e.name as employee,
        e.salary as salary,
        dense_rank() over(
            partition by e.departmentId
            order by e.salary desc
        ) as rnk
    from Employee e
    join Department d
    on e.departmentId = d.id
) t
where rnk <= 3;