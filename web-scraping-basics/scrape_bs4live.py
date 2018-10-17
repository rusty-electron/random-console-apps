import requests
from bs4 import BeautifulSoup

# get the data

data = requests.get('https://umggaming.com/leaderboards')

# parse the html content using bs4
soup = BeautifulSoup(data.text, 'html.parser')

# select the tbody tag with table with given id
leaderboard = soup.find('table', {'id':'leaderboard-table'})
tbody = leaderboard.find('tbody')

# extract the required field from the html
for tr in tbody.find_all('tr'):
    place = tr.find_all('td')[0].text.strip()
    user = tr.find_all('td')[1].find_all('a')[1].text.strip()
    xp = tr.find_all('td')[3].text.strip()

    print(place, user, xp)
