import pandas as pd

def partition(pred):
    while True:
        try:
            user_input = input("Enter a sequence of numbers separated by space (e.g 98 99 100 ...): ")
            seq = list(map(int, user_input.split()))
            break
        except ValueError:
            print("Invalid input, pllease pay attention.")
    
    series = pd.Series(seq)
    filter_series = series.apply(pred)
    df_false = series[~filter_series].tolist()
    df_true = series[filter_series].tolist()
    return df_true, df_false

def is_even(x):
    return x % 2 == 0

df_evens, df_odds = partition(is_even)
print("even numbers:")
print(df_evens)
print("odd numbers:")
print(df_odds)
