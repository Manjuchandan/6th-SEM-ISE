/**
 * Light stop Command where we are encapsulating both Object[light] and the
 * operation[turnOff] together as command. This is the essence of the command.
 *
 */
public class TurnOnLightCommand implements ICommand {
    String l;
    Light light;
 
    public TurnOnLightCommand(Light light,String l) {
        super();
        this.light = light;
	this.l=l;
    }
 
    public void execute() {
        System.out.println("Turning on light in  "+l);
        light.turnOn();
    }
}
