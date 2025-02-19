-- 코드를 입력하세요

select PT_NAME, PT_NO, GEND_CD, AGE, 
CASE WHEN TLNO is not NULL then TLNO ELSE 'NONE' end

from PATIENT 
where AGE <= 12 and GEND_CD = 'W' 
ORDER BY AGE desc, pt_name asc

# ((SELECT PT_NAME, PT_NO, GEND_CD, AGE, TLNO 
# from PATIENT where TLNO is not NULL) 
# UNION
# (select PT_NAME, PT_NO, GEND_CD, AGE, 'NONE' as TLNO 
# from PATIENT where TLNO is NULL)) as T

# where AGE <= 12 and GEND_CD = 'W' 
# ORDER BY AGE desc, pt_name asc