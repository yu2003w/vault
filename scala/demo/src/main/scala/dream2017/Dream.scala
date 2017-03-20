package dream2017

object Dream2017 extends Greeting with App {
  println(greeting)
}

trait Greeting {
  lazy val greeting: String = "hello 2017"
}
