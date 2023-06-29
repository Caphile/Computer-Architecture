from tkinter import filedialog, Tk
import pandas as pd
import os

txt = 1
excel = 2
json = 3

def filePaths(opt = 1):
    root = Tk()
    root.withdraw()

    if opt == txt:    # txt
        fullPaths = filedialog.askopenfilenames(title = 'Select txt Files', initialdir = os.getcwd(), filetypes = [("Text files", "*.txt"), ("All files", "*.*")])
    elif opt == excel:  # excel
        fullPaths = filedialog.askopenfilenames(title = 'Select Excel File', initialdir = os.getcwd(), filetypes=[('Excel files', ('*.csv', '*.xlsx')), ("All files", "*.*")])
    elif opt == json:  # json
        fullPaths = filedialog.askopenfilenames(title = 'Select JSON File', initialdir = os.getcwd(), filetypes=[('JSON files', ('*.json')), ("All files", "*.*")])

    paths, names = [], []
    for p in fullPaths:
        temp = p.split('/')
        paths.append('/'.join(temp[ : -1]))
        names.append(temp[-1])
    
    return paths, names

def readFile(path, name, opt = txt):
    if opt == txt:
        with open(f'{path}/{name}', 'r', encoding = 'utf8') as f:
            data = f.readlines()
        for i in range(len(data)):
            data[i] = data[i].replace('\n', '')
    elif opt == excel:
        data = pd.read_excel(f'{path}/{name}')

    return data

def saveFile(path, name, data, opt = txt, cols = None):
    if opt == txt:
        with open(f'{path}/{name}', 'w', encoding ='utf8') as f:
            for line in data:
                f.write(line + '\n')
    elif opt == excel:
        df = pd.DataFrame(data, columns = cols)
        df.to_excel(f'{path}/{name}', index = False)