package dream2017

import org.scalatest._

class DreamSpec extends FlatSpec with Matchers {
  "The Dream2017 object" should "say hello 2017" in {
    Dream2017.greeting shouldEqual "hello 2017"
  }
}
