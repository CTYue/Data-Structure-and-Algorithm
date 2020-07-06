/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-05-06 13:43:43
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-05-06 13:47:47
 * @Description: To be added.
 */

 function run()
 {
    var foo="foo";
    var bar="bar";

    console.log(foo, bar)
    {
        let baz= "Bazz";
        console.log(baz);
    }

        // console.log(baz);
    }
 run();

 var funcs=[];
 for(var i=0;i<3;i++)
 {
    funcs[i]=function()
    {
        console.log("Value: "+i);
    }
 }