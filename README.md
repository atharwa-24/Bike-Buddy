# Bike-Buddy

## Inspiration
Motorcycles are by their nature far less crashworthy than closed vehicles. They are also less visible to other drivers and pedestrians and less stable than four-wheel vehicles. Operating a motorcycle requires a different combination of physical and mental skills than those used in driving four-wheel vehicles. Motorcyclists and their passengers are more vulnerable to the hazards of weather and road conditions than drivers in closed vehicles.

In 2018, 4,985 motorcyclists died in motorcycle crashes and 857 bicyclists were killed in traffic crashes in the United States. Bike Buddy is a simple solution to this problem. It updates the website with the pre-crash data of a vehicle and also the position of the crashed vehicle. The amount of death and loss due to accidents is immense, especially for the victims who could be saved but weren't due to the lack of available communications with the medical support system. With this and a few close calls ourselves we came up with this project.

## What it does
We have embedded piezo-sensors, an accelerometer, a GPS module and Node-MCU into a motorcycle jacket. When the driver meets with an accident(whether they are hit or fall down), the piezo-sensors are activated which in turn activates the GPS module which then relays the location of the rider to Google Firebase and displays the location on a website for easy access by the Emergency services.

## How we built it
We used a few piezo sensors strategically placed at places that would feel the pressure after being hit during an accident, a neo-6m GPS module and a Node-MCU.

## Challenges we ran into
The GPS module took some time to get up and running.

## Accomplishments that we're proud of
Integrating hardware, GPS services, a website and a cloud to create an exciting and helpful project!

## What we learned
Always reset your Node-MCU before uploading new code otherwise you will waste a lot of time compiling and running the right code and getting wrong results.

## What's next for Bike Buddy
To deploy the website in real life for Emergency services and increase accuracy of GPS module.
