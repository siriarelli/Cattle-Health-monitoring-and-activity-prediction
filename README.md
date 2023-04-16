# Cattle-Health-monitoring-and-activity-prediction
This is an IoT based device designed to monitor the health of the cattle and predict its activity like Eating, Sitting, Walking. Prediction of activity helps in clear understanding of behavioural changes in cattle. The data from sensors is sent to Thingspeak using NodeMCU. Later the data is sent into an algorithm where the activity of the cattle will be predicted.
## Components Used:
Pulse sensor, temperature sensor, accelerometer,  NodeMCU, etc.
## Libraries used:
Numpy, Pandas
## How to use:
1. Connect the components as in circuit diagram and upload the code to nodemcu using arduino IDE after calibrating the sensors.
2. Connnect the device to thingspeak cloud and make sure that the data is being transferred.
3. Now connect thingspeak to the colab file using thingspeak library.
4. The predictions made will be displayed in excel sheet.
## Future Scope
1. Building an app interface.
2. Extending the project to manage large no. of cattle.
