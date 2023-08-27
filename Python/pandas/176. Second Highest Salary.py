import pandas as pd


def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    n = 2
    employee = employee[['salary']].drop_duplicates()
    employee = employee.nlargest(n, 'salary')
    if len(employee) > 1:
        ans = int(employee.iloc[n - 1])
    else:
        ans = None
    return pd.DataFrame({'SecondHighestSalary': [ans]})
