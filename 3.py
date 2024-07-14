import pandas as pd

def chunkify(s, n, fill='x'):
    series = pd.Series(list(s))

    num_chunks = -(-len(s) // n) 
    chunk_df = pd.DataFrame({'chunk': series.groupby(series.index // n).agg(''.join)})   
    chunk_df['chunk'] = chunk_df['chunk'].str.ljust(n, fill)
    return chunk_df['chunk'].tolist()

def main():
    s = input("Enter a string: ")
    n = int(input("Enter chunk size: "))
    fill = input("Enter fill character (default is 'x'): ") or 'x'
    chunks = chunkify(s, n, fill)
    print("Chunks of size", n, "with fill character", fill, ":")
    for chunk in chunks:
        print(chunk)

if __name__ == "__main__":
    main()
