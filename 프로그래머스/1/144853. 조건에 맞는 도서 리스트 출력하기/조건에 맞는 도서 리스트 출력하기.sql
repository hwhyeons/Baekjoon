-- 코드를 입력하세요
SELECT book_id, left(PUBLISHED_DATE,10)
from book
where category = '인문' and PUBLISHED_DATE like '%2021%'
order by PUBLISHED_DATE asc