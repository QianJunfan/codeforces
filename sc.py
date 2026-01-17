import os
import re
from datetime import datetime, timedelta
from collections import Counter, defaultdict

def get_raw_data():
    problems = defaultdict(list)
    pattern = re.compile(r"/\*\s*(.*?)\s*\n\s*\*\s*(.*?)\s*\n", re.DOTALL)
    for f in [f for f in os.listdir('.') if f.endswith('.cpp')]:
        try:
            with open(f, 'r', encoding='utf-8') as src:
                match = pattern.search(src.read(500))
                if match:
                    title, d_str = match.group(1).strip(), match.group(2).strip()
                    dt = datetime.strptime(d_str, "%b %d, %Y").date()
                    problems[dt].append(title)
        except: continue
    return problems

def get_glyph(n, future):
    if future: return "*"
    return "░▒▓█"[(n > 0) + (n > 3) + (n > 8)]

def run():
    data = get_raw_data()
    counts = {d: len(titles) for d, titles in data.items()}
    today = datetime.now().date()
    
    # Heatmap Section
    start = today - timedelta(days=(today.weekday() + 1) % 7, weeks=29)
    grid = {d: [] for d in ["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"]}
    
    for i in range(210):
        curr = start + timedelta(days=i)
        grid[curr.strftime("%a")].append(get_glyph(counts.get(curr, 0), curr > today))

    print("LAST-30-WEEK ACTIVITY HEATMAP:\n")
    for day in ["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"]:
        print(f"        {day} {' '.join(grid[day])}")
    
    latest = max(data.keys() or [today])
    print(f"\n        Latest: {latest}, ░:[0], ▒:(0,3], ▓:(3,8], █:(8,∞), *:Future")

    # Log Section
    print("\n\n\n")
    for dt in sorted(data.keys(), reverse=True):
        print(f"{dt.strftime('%b %d, %Y')}:")
        for title in data[dt]:
            print(f"        {title}")
        print()

if __name__ == "__main__":
    run()
