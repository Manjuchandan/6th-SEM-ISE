/**
 * Fan stop Command where we are encapsulating both Object[fan] and the
 * operation[stop] together as command. This is the essence of the command.
 *
 */
public class StopFanCommand implements ICommand {
    String f;
    Fan fan;
 
    public StopFanCommand(Fan fan,String f) {
        super();
        this.fan = fan;
	this.f=f;
    }
 
    public void execute() {
        System.out.println("stopping Fan in "+f);
        fan.stop();
    }
}
