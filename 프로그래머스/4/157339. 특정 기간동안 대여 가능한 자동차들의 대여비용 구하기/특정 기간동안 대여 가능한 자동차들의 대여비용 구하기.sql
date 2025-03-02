-- 코드를 입력하세요
with JT as (
    SELECT CAR_ID, c1.CAR_TYPE, DAILY_FEE, OPTIONS, DURATION_TYPE, DISCOUNT_RATE, PLAN_ID from CAR_RENTAL_COMPANY_CAR as c1 join CAR_RENTAL_COMPANY_DISCOUNT_PLAN as c2
    on c1.CAR_TYPE = c2.CAR_TYPE and c2.DURATION_TYPE = '30일 이상'
),
JT2 as (
    select CAR_ID, CAR_TYPE, DAILY_FEE, OPTIONS, DURATION_TYPE, DISCOUNT_RATE, PLAN_ID,
        1.0-cast(replace(DISCOUNT_RATE,'\%','') as DECIMAL)/100 as FLOAT_CONST # 30%할인이면 곱하기 0.7
    from JT
),
JT3 as (
    select CAR_ID, CAR_TYPE, DAILY_FEE, OPTIONS, DURATION_TYPE, DISCOUNT_RATE, PLAN_ID, FLOAT_CONST, DAILY_FEE*FLOAT_CONST*30 as FEE
    from JT2
),
JT4 as (
    select CAR_ID, CAR_TYPE, cast(FEE as unsigned) as FEE
    from JT3
    where FEE >= 500000 and FEE < 2000000 and CAR_TYPE in ('세단','SUV')
    order by FEE desc, CAR_TYPE asc, CAR_ID desc
),
REMOVE_LIST as (
    select c1.CAR_ID
    from CAR_RENTAL_COMPANY_CAR as c1
        JOIN CAR_RENTAL_COMPANY_RENTAL_HISTORY as c2
            on c1.CAR_ID = c2.CAR_ID
    where not (END_DATE < str_to_date('2022-11-01','%Y-%m-%d') or START_DATE > str_to_date('2022-11-30','%Y-%m-%d'))
)

# select * from REMOVE_LIST
# select * from CAR_RENTAL_COMPANY_RENTAL_HISTORY where car_id = 18
# 정답 쿼리
select * from JT4 where CAR_ID not in (select * from REMOVE_LIST)

