import pandas as pd
import utils as u

pd.set_option('display.max_columns', None)
pd.set_option('display.max_rows', None)

#pd.options.display.max_rows = 60
#pd.options.display.max_columns = 20

fp, fn = u.filePaths(u.excel)
for p, n in zip(fp, fn): 
    df = u.readFile(p, n, u.excel)

    new_header = df.iloc[0]
    df.columns = new_header
    df = df[2 : ]
    df.reset_index(drop = True, inplace = True)

    print(df)