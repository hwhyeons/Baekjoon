-- 코드를 입력하세요
# select sum(cnt) from (SELECT count(*) as cnt from ANIMAL_INS group by name having name is not null) as T
select count(*) from (select distinct(name) from ANIMAL_INS where name is not null) as T