import requests
import re

# get the data from the desired page
data = requests.get('http://127.0.0.1:5500/scrape.html')


# extract the phone numbers, emails, etc using regex
phones = re.findall(r'(\(?[0-9]{3}\)?(?:\-|\s|\.)?[0-9]{3}(?:\-|\.)[0-9]{4})', data.text)
emails = re.findall(r'([\d\w\.]+@[\d\w\.\-]+\.\w+)', data.text)

print(phones,emails)