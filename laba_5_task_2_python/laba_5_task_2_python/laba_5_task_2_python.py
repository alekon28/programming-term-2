def change(regions,command):
    region = command[1]
    new_center = command[2]
    region_exists = bool(0)

    if region in regions:
        region_exists = 1
        old_center = regions[region]

    regions[region] = new_center

    if region_exists:
        print("Region ",region," has changed its administrative center from ",old_center," to ",new_center)
    else:
        print("New region ",region," with administrative center ",new_center)

def rename(regions,command):
    old_region = command[1]
    new_region = command[2]

    for i in regions.keys():
        if i == old_region:
            old_center = regions[i]
            regions.pop(i)
            regions[new_region] = old_center
            print(old_region," has been renamed to ",new_region)
            break;

def about(regions,command):
    region = command[1]

    if region in regions:
        print(region," has administrative center ",regions[region])
    else:
        print("Incorrect")

def all(regions):
    for i in regions.keys():
        print(i," - ",regions[i])

regions = dict()
number_requests = int(input())

for i in range(number_requests):
    command = input().split()
    if command[0] == "CHANGE":
        change(regions,command)
    if command[0] == "RENAME":
        rename(regions,command)
    if command[0] == "ABOUT":
        about(regions,command)
    if command[0] == "ALL":
        all(regions)

