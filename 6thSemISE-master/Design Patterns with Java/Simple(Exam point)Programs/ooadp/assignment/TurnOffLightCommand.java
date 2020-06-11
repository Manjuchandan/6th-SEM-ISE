/**
 * Light Start Command where we are encapsulating both Object[light] and the
 * operation[turnOn] together as command. This is the essence of the command.
 *
 */
public class TurnOffLightCommand implements ICommand {
    String l;
    Light light;
 
    public TurnOffLightCommand(Light light,String l) {
        super();
        this.light = light;
	this.l=l;
    }
 
    public void execute() {
        System.out.println("Turning off light in  "+l);
        light.turnOff();
    }
}
