import urllib.request
import argparse

parser = argparse.ArgumentParser()
parser.add_argument("-u", "--url", default="https://cbseresults.nic.in", help="website link")
args = vars(parser.parse_args())

url = args["url"]
code = 0

while(code!=200):
    print(f"[status] trying site: {url}")
    try:
        code = urllib.request.urlopen(url).getcode()
        print(f"[{code}] Website loaded")
    except urllib.error.URLError:
        print("[Error] lol, issue found!")
    print("")
