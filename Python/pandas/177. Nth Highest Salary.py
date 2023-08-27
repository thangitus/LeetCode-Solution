import pandas as pd


def nth_highest_salary(employee: pd.DataFrame, n: int) -> pd.DataFrame:
    employee = employee[['salary']].drop_duplicates()
    employee = employee.nlargest(n, 'salary')
    if len(employee) > n - 1:
        ans = int(employee.iloc[n - 1])
    else:
        ans = None
    return pd.DataFrame({'SecondHighestSalary': [ans]})
