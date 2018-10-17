import requests
from bs4 import BeautifulSoup

# get the data
data = requests.get('http://127.0.0.1:5500/scrape.html')

# parse the html content using bs4
soup = BeautifulSoup(data.text, 'html.parser')

# find all 'td' within 'tr' and append to data list
data = []
for tr in soup.find_all('tr'):
    values = [td.text for td in tr.find_all('td')] 
    data.append(values)

# specifying a special class for the same
data = []
for tr in soup.find_all('tr', { 'class':'special'}):
    values = [td.text for td in tr.find_all('td')] 
    data.append(values)

print(data)