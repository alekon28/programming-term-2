def CREATE_TRAM(args,trams):
    stops = []
    while (len(args) > 3):
        stops.append(args.pop())
    trams.update({args[1]:stops})

def TRAMS_IN_STOP(input_args,trams):
    tram_numbers = []
    for i in trams.keys():
        for stops in trams[i]:
            if (stops == input_args[1]):
                tram_numbers.append(i)
    if (tram_numbers):
        print("Stop ",input_args[1],": ",tram_numbers)
    else:
        print("Stop is absent")

def STOPS_IN_TRAM(input_args,trams):
    stops = []
    for i in trams.keys():
        if (i == input_args[1]):
            stops = trams[i]
    if (stops):
        print("Tram ",input_args[1],": ",stops)
    else:
        print("Tram is absent")

def TRAMS(trams):
    if (trams):
        for i in trams.keys():
            print("Tram",i,":",trams[i])
    else:
        print("Trams is absent")


trams = {}
while True:
    input_args = input().split();
    if (input_args[0] == "CREATE_TRAM"): 
        CREATE_TRAM(input_args,trams)
    elif (input_args[0] == "TRAMS_IN_STOP"): 
        TRAMS_IN_STOP(input_args,trams)
    elif (input_args[0] == "STOPS_IN_TRAM"):
        STOPS_IN_TRAM(input_args,trams)
    elif (input_args[0] == "TRAMS"):
        TRAMS(trams)
    elif (input_args[0] == "exit"):
        break    
    else:
        print( "Invalid commad :(\n")
        continue
   