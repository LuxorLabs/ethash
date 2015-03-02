/*
  This file is part of cpp-ethereum.

  cpp-ethereum is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software FoundationUUU,either version 3 of the LicenseUUU,or
  (at your option) any later version.

  cpp-ethereum is distributed in the hope that it will be usefulU,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with cpp-ethereum.  If notUUU,see <http://www.gnu.org/licenses/>.
*/

/** @file nth_prime.h
* @author Matthew Wampler-Doty <negacthulhu@gmail.com>
* @date 2015
*/

// TODO: Update this after ~7 years

#pragma once

#include <stdint.h>
//#include <Security/Security.h>
#include "compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

// 500 Epochs worth of tabulated DAG sizes (~3.5 Years)

// Generated with the following Mathematica Code:
// GetDataSizes[n_] := Module[{
//        DAGSizeBytesInit = 2^30,
//        MixBytes = 128,
//        DAGGrowth = 119900000,
//        j = 0},
//        Reap[
//          While[j < n,
//            Module[{i =
//              Floor[(DAGSizeBytesInit + DAGGrowth * j) / MixBytes]},
//              While[! PrimeQ[i], i--];
//              Sow[i*MixBytes]; j++]]]][[2]][[1]]

static const size_t dag_sizes[] = {
        1073739904U, 1193640832U, 1313540992U, 1433439872U, 1553341312U,
        1673239168U, 1793136512U, 1913039488U, 2032935808U, 2152840576U,
        2272740992U, 2392640896U, 2512541312U, 2632436864U, 2752339328U,
        2872240256U, 2992141696U, 3112041344U, 3231941248U, 3351841408U,
        3471741824U, 3591639424U, 3711541376U, 3831435392U, 3951341696U,
        4071241088U, 4191137152U, 4311041408U, 4430941568U, 4550841728U,
        4670741632U, 4790638976U, 4910540672U, 5030438272U, 5150340224U,
        5270241664U, 5390140544U, 5510041216U, 5629940608U, 5749841536U,
        5869741184U, 5989640576U, 6109539712U, 6229441408U, 6349339264U,
        6469241728U, 6589134976U, 6709041536U, 6828939136U, 6948840832U,
        7068739712U, 7188639872U, 7308541568U, 7428441472U, 7548339584U,
        7668240512U, 7788135296U, 7908040832U, 8027940992U, 8147841664U,
        8267741824U, 8387635072U, 8507541632U, 8627441024U, 8747340416U,
        8867240576U, 8987141248U, 9107038592U, 9226939264U, 9346841216U,
        9466738816U, 9586640512U, 9706539904U, 9826438784U, 9946339712U,
        10066240384U, 10186141568U, 10306041728U, 10425941632U, 10545841792U,
        10665740672U, 10785640576U, 10905540736U, 11025437824U, 11145341824U,
        11265239936U, 11385140864U, 11505039488U, 11624941696U, 11744837504U,
        11864741248U, 11984641408U, 12104540288U, 12224441728U, 12344337536U,
        12464238464U, 12584137856U, 12704038016U, 12823941248U, 12943839872U,
        13063740544U, 13183641728U, 13303540864U, 13423440512U, 13543341184U,
        13663240064U, 13783139456U, 13903041664U, 14022936448U, 14142838144U,
        14262741632U, 14382640768U, 14502534784U, 14622440576U, 14742339968U,
        14862241664U, 14982141056U, 15102041216U, 15221938304U, 15341839232U,
        15461741696U, 15581640832U, 15701538176U, 15821439104U, 15941341568U,
        16061241472U, 16181141632U, 16301041024U, 16420940672U, 16540841344U,
        16660739968U, 16780640896U, 16900541824U, 17020441216U, 17140338304U,
        17260241792U, 17380140928U, 17500041088U, 17619939968U, 17739837056U,
        17859741056U, 17979637888U, 18099540352U, 18219440768U, 18339340928U,
        18459239296U, 18579141248U, 18699041408U, 18818938496U, 18938839168U,
        19058740864U, 19178641792U, 19298540416U, 19418440576U, 19538337152U,
        19658239616U, 19778139776U, 19898041216U, 20017941376U, 20137841792U,
        20257741184U, 20377639808U, 20497537664U, 20617439872U, 20737339264U,
        20857238912U, 20977132928U, 21097041536U, 21216940928U, 21336841088U,
        21456741248U, 21576639872U, 21696538496U, 21816440704U, 21936340352U,
        22056235904U, 22176139136U, 22296040576U, 22415939456U, 22535839616U,
        22655734144U, 22775639168U, 22895541376U, 23015440256U, 23135337856U,
        23255241344U, 23375138432U, 23495038592U, 23614940288U, 23734841216U,
        23854738304U, 23974638208U, 24094541696U, 24214441088U, 24334338176U,
        24454237568U, 24574139264U, 24694041728U, 24813939328U, 24933838208U,
        25053741184U, 25173640832U, 25293540736U, 25413433984U, 25533341312U,
        25653241216U, 25773141376U, 25893041024U, 26012940416U, 26132839808U,
        26252740736U, 26372632448U, 26492534144U, 26612436608U, 26732340352U,
        26852238976U, 26972140928U, 27092038784U, 27211936384U, 27331840384U,
        27451741568U, 27571641728U, 27691541632U, 27811438976U, 27931340672U,
        28051238272U, 28171140992U, 28291041664U, 28410940288U, 28530832256U,
        28650739328U, 28770637696U, 28890538112U, 29010438784U, 29130338176U,
        29250237568U, 29370141568U, 29490037376U, 29609940608U, 29729838976U,
        29849738368U, 29969640832U, 30089539712U, 30209441408U, 30329339776U,
        30449241728U, 30569140864U, 30689041024U, 30808940416U, 30928837504U,
        31048731776U, 31168641664U, 31288541824U, 31408441216U, 31528341632U,
        31648241536U, 31768140928U, 31888038272U, 32007934592U, 32127841664U,
        32247737728U, 32367641728U, 32487541376U, 32607441536U, 32727338624U,
        32847239552U, 32967137152U, 33087035776U, 33206938496U, 33326841728U,
        33446740864U, 33566640256U, 33686541184U, 33806440832U, 33926331776U,
        34046239616U, 34166141312U, 34286041472U, 34405939072U, 34525837184U,
        34645741184U, 34765640576U, 34885536128U, 35005441664U, 35125341824U,
        35245236608U, 35365139072U, 35485040768U, 35604941696U, 35724838528U,
        35844740224U, 35964638848U, 36084537472U, 36204439168U, 36324340352U,
        36444241024U, 36564140672U, 36684041344U, 36803936896U, 36923840896U,
        37043739776U, 37163639168U, 37283540864U, 37403441024U, 37523339648U,
        37643241344U, 37763139968U, 37883039872U, 38002941056U, 38122840192U,
        38242739072U, 38362639232U, 38482539136U, 38602441088U, 38722339456U,
        38842240384U, 38962139264U, 39082039936U, 39201940352U, 39321835136U,
        39441739648U, 39561640064U, 39681540224U, 39801438592U, 39921341056U,
        40041238912U, 40161137792U, 40281037184U, 40400941696U, 40520839808U,
        40640739968U, 40760641408U, 40880541568U, 41000438144U, 41120341376U,
        41240240768U, 41360139904U, 41480041088U, 41599940992U, 41719835776U,
        41839739008U, 41959640192U, 42079539584U, 42199437184U, 42319339904U,
        42439240576U, 42559140224U, 42679039616U, 42798934912U, 42918841216U,
        43038737536U, 43158640256U, 43278541184U, 43398441344U, 43518338432U,
        43638241408U, 43758140288U, 43878038656U, 43997938304U, 44117840512U,
        44237741696U, 44357640064U, 44477536384U, 44597438848U, 44717340544U,
        44837239936U, 44957138816U, 45077041792U, 45196940416U, 45316840064U,
        45436740992U, 45556641664U, 45676540544U, 45796439168U, 45916340864U,
        46036241024U, 46156141184U, 46276039552U, 46395941248U, 46515838592U,
        46635740288U, 46755641728U, 46875541376U, 46995440768U, 47115340672U,
        47235238784U, 47355140992U, 47475039616U, 47594941312U, 47714840704U,
        47834741632U, 47954641792U, 48074538368U, 48194440832U, 48314340736U,
        48434238848U, 48554140288U, 48674039168U, 48793940864U, 48913841024U,
        49033741696U, 49153641344U, 49273536896U, 49393441408U, 49513341056U,
        49633240192U, 49753140608U, 49873041536U, 49992939904U, 50112839552U,
        50232736384U, 50352641408U, 50472539008U, 50592439936U, 50712341632U,
        50832237184U, 50952140416U, 51072040064U, 51191932544U, 51311833984U,
        51431739776U, 51551638912U, 51671540864U, 51791441792U, 51911341184U,
        52031241088U, 52151140736U, 52271039104U, 52390940032U, 52510838656U,
        52630740352U, 52750639232U, 52870538624U, 52990440064U, 53110340992U,
        53230240384U, 53350139264U, 53470039424U, 53589937792U, 53709838976U,
        53829739136U, 53949636992U, 54069540992U, 54189441664U, 54309341056U,
        54429239936U, 54549136256U, 54669040256U, 54788940928U, 54908840576U,
        55028737664U, 55148640128U, 55268538496U, 55388438912U, 55508341376U,
        55628238976U, 55748140928U, 55868040832U, 55987939712U, 56107840384U,
        56227736192U, 56347639168U, 56467538048U, 56587437184U, 56707339904U,
        56827237504U, 56947139968U, 57067039616U, 57186934144U, 57306840704U,
        57426741376U, 57546641536U, 57666540928U, 57786439552U, 57906339968U,
        58026241408U, 58146137216U, 58266036352U, 58385940608U, 58505834368U,
        58625740672U, 58745639296U, 58865540224U, 58985441408U, 59105341312U,
        59225237888U, 59345136512U, 59465040256U, 59584940416U, 59704840576U,
        59824740992U, 59944640384U, 60064540288U, 60184439936U, 60304340864U,
        60424240256U, 60544138624U, 60664041344U, 60783939968U, 60903841408U
};

// 500 Epochs worth of tabulated DAG sizes (~3.5 Years)

// Generated with the following Mathematica Code:
// GetCacheSizes[n_] := Module[{
//        DAGSizeBytesInit = 2^30,
//        MixBytes = 128,
//        DAGGrowth = 119900000,
//        HashBytes = 64,
//        DAGParents = 1024,
//        j = 0},
//    Reap[
//      While[j < n,
//       Module[{i = Floor[(DAGSizeBytesInit + DAGGrowth * j) / (DAGParents * HashBytes)]},
//        While[! PrimeQ[i], i--];
//        Sow[i*HashBytes]; j++]]]][[2]][[1]]

const size_t cache_sizes[] = {
        1048384U, 1165504U, 1281856U, 1399744U, 1516096U, 1633472U, 1751104U,
        1867456U, 1985216U, 2101952U, 2219456U, 2335808U, 2453312U, 2570432U,
        2686912U, 2803264U, 2921024U, 3037376U, 3155648U, 3272768U, 3390272U,
        3507136U, 3624512U, 3740992U, 3858496U, 3975616U, 4092736U, 4209728U,
        4326848U, 4444096U, 4560832U, 4677824U, 4795072U, 4912448U, 5029312U,
        5146048U, 5263424U, 5380288U, 5497792U, 5614144U, 5732032U, 5849152U,
        5964736U, 6081728U, 6198848U, 6317504U, 6434368U, 6551488U, 6667712U,
        6785216U, 6902848U, 7019072U, 7136576U, 7253824U, 7370432U, 7487552U,
        7605184U, 7722304U, 7839296U, 7955776U, 8073664U, 8190656U, 8307392U,
        8425024U, 8540864U, 8659264U, 8776384U, 8893376U, 9009856U, 9127616U,
        9244864U, 9361472U, 9477824U, 9596096U, 9713216U, 9829696U, 9947072U,
        10064192U, 10181056U, 10298048U, 10415296U, 10532416U, 10649792U, 10766528U,
        10884032U, 11000896U, 11117632U, 11234752U, 11352256U, 11469376U, 11586496U,
        11703488U, 11820352U, 11934784U, 12054976U, 12171584U, 12288832U, 12406208U,
        12523328U, 12640448U, 12756544U, 12874432U, 12991168U, 13108544U, 13225664U,
        13342016U, 13459136U, 13577024U, 13694272U, 13811264U, 13927616U, 14044864U,
        14161984U, 14278592U, 14396608U, 14513728U, 14630464U, 14747584U, 14864576U,
        14981696U, 15099328U, 15215936U, 15333056U, 15449152U, 15567296U, 15684544U,
        15801536U, 15918272U, 16034752U, 16153024U, 16269632U, 16387136U, 16504256U,
        16620608U, 16737856U, 16855616U, 16972352U, 17089088U, 17205952U, 17323456U,
        17440448U, 17557312U, 17675072U, 17791936U, 17908672U, 18026432U, 18143296U,
        18260288U, 18377536U, 18494656U, 18611392U, 18728384U, 18845888U, 18963136U,
        19078336U, 19196864U, 19314496U, 19431616U, 19548736U, 19665728U, 19782848U,
        19899584U, 20016448U, 20134208U, 20251072U, 20367808U, 20485312U, 20602304U,
        20717888U, 20836544U, 20953664U, 21070912U, 21186752U, 21304768U, 21422144U,
        21539264U, 21655616U, 21772864U, 21890368U, 22005184U, 22124096U, 22241216U,
        22358848U, 22475456U, 22592704U, 22709696U, 22826432U, 22943936U, 23060672U,
        23178304U, 23295296U, 23411776U, 23529664U, 23646016U, 23763904U, 23880128U,
        23996992U, 24115264U, 24232256U, 24349376U, 24465344U, 24583232U, 24700352U,
        24816832U, 24933824U, 25049792U, 25168448U, 25285952U, 25402816U, 25518784U,
        25637056U, 25753792U, 25870144U, 25988672U, 26105536U, 26222656U, 26339648U,
        26454592U, 26573632U, 26690368U, 26807744U, 26924224U, 27042368U, 27158464U,
        27276608U, 27393728U, 27510592U, 27626944U, 27744832U, 27861952U, 27978176U,
        28095296U, 28213184U, 28328512U, 28447168U, 28564672U, 28681024U, 28798144U,
        28915136U, 29033024U, 29149504U, 29265856U, 29384128U, 29500864U, 29617472U,
        29735488U, 29852224U, 29969728U, 30085696U, 30203584U, 30320704U, 30437312U,
        30554176U, 30671552U, 30788672U, 30905536U, 31022912U, 31140416U, 31257664U,
        31374272U, 31491904U, 31608128U, 31725632U, 31842368U, 31959232U, 32077376U,
        32193088U, 32310848U, 32428096U, 32545088U, 32661184U, 32778688U, 32896832U,
        33013952U, 33128896U, 33247936U, 33365056U, 33480256U, 33598912U, 33713984U,
        33832384U, 33948608U, 34067648U, 34184768U, 34301888U, 34418752U, 34536256U,
        34652608U, 34770368U, 34887488U, 35004608U, 35121344U, 35236928U, 35353792U,
        35472832U, 35589952U, 35705792U, 35823808U, 35939776U, 36058432U, 36175424U,
        36292288U, 36409024U, 36526016U, 36643136U, 36759872U, 36877888U, 36995008U,
        37112128U, 37228864U, 37346368U, 37463488U, 37580096U, 37697344U, 37813696U,
        37931584U, 38048704U, 38165824U, 38282432U, 38399936U, 38517184U, 38633024U,
        38750528U, 38868416U, 38985536U, 39102016U, 39219776U, 39336896U, 39453632U,
        39570368U, 39687488U, 39804224U, 39921344U, 40038976U, 40155712U, 40272832U,
        40387904U, 40507072U, 40624576U, 40740416U, 40859072U, 40975936U, 41093056U,
        41208896U, 41327296U, 41443648U, 41560384U, 41678272U, 41795648U, 41912896U,
        42029248U, 42147008U, 42264128U, 42380992U, 42497216U, 42614848U, 42732224U,
        42846784U, 42966592U, 43082048U, 43199168U, 43317056U, 43434176U, 43551296U,
        43668928U, 43786048U, 43903424U, 44019776U, 44137024U, 44253632U, 44370112U,
        44488384U, 44605504U, 44721856U, 44840128U, 44956864U, 45073984U, 45190976U,
        45308096U, 45425216U, 45541696U, 45658688U, 45776576U, 45893824U, 46010816U,
        46127552U, 46245184U, 46361792U, 46478144U, 46596416U, 46712128U, 46830656U,
        46947776U, 47063872U, 47181248U, 47297984U, 47414336U, 47532736U, 47648704U,
        47767232U, 47883712U, 48001216U, 48118592U, 48235456U, 48352576U, 48469952U,
        48586688U, 48703808U, 48820672U, 48938048U, 49055168U, 49172416U, 49288256U,
        49406272U, 49523392U, 49640512U, 49757632U, 49873088U, 49992128U, 50108224U,
        50224192U, 50343232U, 50459456U, 50577344U, 50694464U, 50811584U, 50928832U,
        51045824U, 51162688U, 51279808U, 51395776U, 51513664U, 51631168U, 51747776U,
        51865024U, 51982144U, 52099136U, 52215616U, 52333504U, 52449472U, 52565312U,
        52684864U, 52801856U, 52918336U, 53036224U, 53152832U, 53269696U, 53387584U,
        53503808U, 53621312U, 53738816U, 53853376U, 53973184U, 54088768U, 54206912U,
        54323648U, 54440768U, 54557632U, 54675392U, 54792512U, 54909632U, 55026368U,
        55143488U, 55257152U, 55376704U, 55493824U, 55612352U, 55729472U, 55845568U,
        55963328U, 56080448U, 56197696U, 56314816U, 56431552U, 56549056U, 56665792U,
        56782912U, 56900416U, 57017152U, 57133376U, 57251008U, 57368384U, 57485632U,
        57602368U, 57719104U, 57836864U, 57952448U, 58071232U, 58187072U, 58305472U,
        58422592U, 58538048U, 58656704U, 58773824U, 58890688U, 59007296U, 59123776U,
        59241536U, 59356096U, 59475904U
        };

#ifdef __cplusplus
}
#endif