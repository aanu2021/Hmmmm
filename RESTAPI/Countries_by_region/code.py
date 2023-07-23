import requests

def get_weather_records(region, keyword):
    base_url = "https://jsonmock.hackerrank.com/api/countries/search"
    page = 1
    records = []

    while True:
        url = f"{base_url}?region={region}&name={keyword}&page={page}"
        response = requests.get(url)

        if response.status_code == 200:
            data = response.json()
            total_pages = data['total_pages']
            records.extend(data['data'])

            if page >= total_pages:
                break

            page += 1
        else:
            print(f"Error: Unable to fetch data for page {page}")
            break

    return records

if __name__ == "__main__":
    region = "region"  #asia, europe
    keyword = "keyword"  # ind , de , fra

    weather_records = get_weather_records(region, keyword)

    # Process the weather records as needed
    print(weather_records)
