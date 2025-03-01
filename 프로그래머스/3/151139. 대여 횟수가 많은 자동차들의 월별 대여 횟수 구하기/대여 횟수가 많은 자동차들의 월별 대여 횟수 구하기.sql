-- 코드를 입력하세요
# 아니면 어려우면, 8월만 받아서 처리 후에 같은 로직으로 9,10월 받아서 union?
# MONTH끼리 일단 묶고, 최종적으로 MONTH가 8,9,10인 것만 출력하면 될듯

# test
# select * from CAR_RENTAL_COMPANY_RENTAL_HISTORY order by car_id

with tt as (
    SELECT 8 as MONTH, CAR_ID, count(*) as RECORDS from CAR_RENTAL_COMPANY_RENTAL_HISTORY where start_date like '2022-08%' group by CAR_ID
union
SELECT 9 as MONTH, CAR_ID, count(*) as RECORDS from CAR_RENTAL_COMPANY_RENTAL_HISTORY where start_date like '2022-09%' group by CAR_ID
union
SELECT 10 as MONTH, CAR_ID, count(*) as RECORDS from CAR_RENTAL_COMPANY_RENTAL_HISTORY where start_date like '2022-10%' group by CAR_ID
),
K as (select CAR_ID, sum(RECORDS) from tt group by CAR_ID having sum(RECORDS) >= 5)

select * from tt
where CAR_ID in (select CAR_ID from k) and RECORDS != 0
order by MONTH asc, CAR_ID desc