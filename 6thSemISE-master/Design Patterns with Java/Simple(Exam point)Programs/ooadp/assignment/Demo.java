
public class Demo   //client
{
    public static void main(String[] args) 
    {
        Light livingRoomLight = new Light();    //receiver 1
 
        Fan livingRoomFan = new Fan();  //receiver 2
 
        Light bedRoomLight = new Light();   //receiver 3
 
        Fan bedRoomFan = new Fan();     //receiver 4
 
        HomeAutomationRemote remote = new HomeAutomationRemote();   //Invoker
	ICommand l =  new TurnOnLightCommand(livingRoomLight,"livingRoom");
        remote.setCommand(l);
        remote.buttonPressed();

	ICommand b = new TurnOnLightCommand( bedRoomLight,"bedRoom" );
        remote.setCommand(b);
        remote.buttonPressed();
 
	ICommand b2 =new StartFanCommand( bedRoomFan,"bedRoom" );
        remote.setCommand(b2);
        remote.buttonPressed();

	ICommand b3 = new StopFanCommand( bedRoomFan,"bedRoom" );
        remote.setCommand(b3);
        remote.buttonPressed();
    }
}
