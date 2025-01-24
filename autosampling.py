import sys
import re
import requests
from pathlib import Path
from bs4 import BeautifulSoup

def touchSample(path, inputs):
    for i in range(len(inputs)):
        file_path = Path(f"{path}/{i+1}.in")
        file_path.touch(exist_ok=True)

        file_path.write_text(inputs[i], encoding="utf-8")

def do(problem_number):
    address = f"https://icpc.me/{problem_number}"

    response = requests.get(address, headers={'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36', 'Cookie':'OnlineJudge=i6q6asini5984g80rnc9rojt2m'}).text
    data = BeautifulSoup(response, 'html.parser')

    inputs = data.find_all('pre', id=re.compile(r'sample-input-\d+'))

    inputs = [data.text.strip() for data in inputs]
    folder_path = Path(problem_number)

    if not folder_path.exists():
        folder_path.mkdir(parents=True, exist_ok=True)
        touchSample(folder_path, inputs)
    else:
        touchSample(folder_path, inputs)

if __name__ == "__main__":
    argument = sys.argv
    del argument[0]	
    do(argument[0])