import requests

def get_tv_shows():
    base_url = "https://jsonmock.hackerrank.com/api/series"
    page = 1
    tv_shows = []

    while True:
        url = f"{base_url}?page={page}"
        response = requests.get(url)

        if response.status_code == 200:
            data = response.json()
            total_pages = data['total_pages']
            tv_shows.extend(data['data'])

            if page >= total_pages:
                break

            page += 1
        else:
            print(f"Error: Unable to fetch data for page {page}")
            break

    return tv_shows

if __name__ == "__main__":
    tv_shows = get_tv_shows()

    # Process the TV show data as needed
    for show in tv_shows:
        print(f"Name: {show['name']}")
        print(f"Runtime of Series: {show['runtime of series']}")
        print(f"Certificate: {show['certificate']}")
        print(f"Runtime of Episodes: {show['runtime of episodes']}")
        print(f"Genre: {show['genre']}")
        print(f"IMDb Rating: {show['imdb_rating']}")
        print("\n")
