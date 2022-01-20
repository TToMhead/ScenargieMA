/ /   C o p y r i g h t   ( c )   2 0 0 7 - 2 0 1 7   b y   S p a c e - T i m e   E n g i n e e r i n g ,   L L C   ( " S T E " ) . 
 / /   A l l   R i g h t s   R e s e r v e d . 
 / / 
 / /   T h i s   s o u r c e   c o d e   i s   a   p a r t   o f   S c e n a r g i e   S o f t w a r e   ( " S o f t w a r e " )   a n d   i s 
 / /   s u b j e c t   t o   S T E   S o f t w a r e   L i c e n s e   A g r e e m e n t .   T h e   i n f o r m a t i o n   c o n t a i n e d 
 / /   h e r e i n   i s   c o n s i d e r e d   a   t r a d e   s e c r e t   o f   S T E ,   a n d   m a y   n o t   b e   u s e d   a s 
 / /   t h e   b a s i s   f o r   a n y   o t h e r   s o f t w a r e ,   h a r d w a r e ,   p r o d u c t   o r   s e r v i c e . 
 / / 
 / /   R e f e r   t o   l i c e n s e . t x t   f o r   m o r e   s p e c i f i c   d i r e c t i v e s . 
 
 # i n c l u d e   " m u l t i a g e n t _ b e h a v i o r . h " 
 # i n c l u d e   " m u l t i a g e n t _ a g e n t s i m . h " 
 # i n c l u d e   " m u l t i a g e n t _ r o u t e s e a r c h . h " 
 
 n a m e s p a c e   M u l t i A g e n t   { 
 
 
 s t a t i c   i n l i n e 
 V e r t e x   C a l c u l a t e N e x t V e r t e x ( c o n s t   V e r t e x &   n e x t P o s ,   c o n s t   V e r t e x &   d i r e c t i o n V e c t o r ,   c o n s t   d o u b l e   r e m a i n i n g P a t h D i s t a n c e ) 
 { 
         r e t u r n   n e x t P o s   -   d i r e c t i o n V e c t o r * r e m a i n i n g P a t h D i s t a n c e ; 
 } 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 F r e e W a l k B e h a v i o r : : F r e e W a l k B e h a v i o r ( 
         c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   i n i t A g e n t G i s P t r , 
         c o n s t   s h a r e d _ p t r < P u b l i c V e h i c l e T a b l e > &   i n i t P u b l i c V e h i c l e T a b l e P t r , 
         c o n s t   s h a r e d _ p t r < A g e n t R o u t e > &   i n i t R o u t e P t r , 
         c o n s t   G i s P o s i t i o n I d T y p e &   i n i t E n d P o s i t i o n I d , 
         c o n s t   b o o l   i n i t E n t e r T o P o s i t i o n , 
         c o n s t   A g e n t R e s o u r c e &   i n i t R e s o u r c e ) 
         : 
         A g e n t B e h a v i o r ( i n i t A g e n t G i s P t r ,   i n i t P u b l i c V e h i c l e T a b l e P t r ,   i n i t R o u t e P t r ,   i n i t R e s o u r c e ) , 
         r e m a i n i n g P a t h D i s t a n c e ( 0 ) , 
         e n d P o s i t i o n I d ( i n i t E n d P o s i t i o n I d ) , 
         e x t r a D e s t P o i n I d ( r e s o u r c e . E x t r a D e s t P o i I d ( ) ) , 
         e n t e r T o P o s i t i o n ( i n i t E n t e r T o P o s i t i o n ) 
 { 
         c o n s t   V e r t e x &   c u r r e n t P o s   =   r e s o u r c e . P o s i t i o n ( ) ; 
 
         i f   ( e n t e r T o P o s i t i o n )   { 
                 c o n s t   G i s P o s i t i o n I d T y p e &   e x t r a D e s t P o i I d   =   r e s o u r c e . E x t r a D e s t P o i I d ( ) ; 
 
                 i f   ( e x t r a D e s t P o i I d . I s V a l i d ( ) )   { 
                         a s s e r t ( e x t r a D e s t P o i I d . t y p e   = =   G I S _ P O I ) ; 
                         n e x t P o s   =   t h e A g e n t G i s P t r - > G e t A g e n t P o i ( e x t r a D e s t P o i I d . i d ) . r e f . G e t V e r t e x ( ) ; 
 
                 }   e l s e   { 
                         c o n s t   G i s P o s i t i o n I d T y p e &   d e s t P o s i t i o n I d   =   r e s o u r c e . D e s t P o s i t i o n I d ( ) ; 
 
                         i f   ( d e s t P o s i t i o n I d . t y p e   = =   G I S _ B U I L D I N G )   { 
                                 n e x t P o s   =   t h e A g e n t G i s P t r - > G e t A g e n t B u i l d i n g ( d e s t P o s i t i o n I d . i d ) . r e f . 
                                         G e t R a n d o m P o s i t i o n ( r e s o u r c e . G e t R a n d o m N u m b e r G e n e r a t o r ( ) ) ; 
                         }   e l s e   i f   ( d e s t P o s i t i o n I d . t y p e   = =   G I S _ P A R K )   { 
                                 n e x t P o s   =   t h e A g e n t G i s P t r - > G e t A g e n t P a r k ( d e s t P o s i t i o n I d . i d ) . r e f . 
                                         G e t R a n d o m P o s i t i o n ( r e s o u r c e . G e t R a n d o m N u m b e r G e n e r a t o r ( ) ) ; 
                         }   e l s e   { 
                                 a s s e r t ( d e s t P o s i t i o n I d . t y p e   = =   G I S _ P O I ) ; 
 
                                 n e x t P o s   =   c u r r e n t P o s ; 
                         } 
                 } 
 
         }   e l s e   { 
                 n e x t P o s   =   t h e A g e n t G i s P t r - > G e t V e r t e x ( r e s o u r c e . L a s t V e r t e x I d ( ) ) ; 
         } 
 
         d i r e c t i o n V e c t o r   =   ( n e x t P o s   -   c u r r e n t P o s ) . N o r m a l i z e d ( ) ; 
         r e m a i n i n g P a t h D i s t a n c e   =   c u r r e n t P o s . D i s t a n c e T o ( n e x t P o s ) ; 
 
         r e s o u r c e . S e t D i r e c t i o n R a d i a n s ( d i r e c t i o n V e c t o r . D i r e c t i o n R a d i a n s ( ) ) ; 
 } 
 
 
 
 v o i d   F r e e W a l k B e h a v i o r : : I n c r e m e n t T i m e S t e p ( c o n s t   S i m T i m e &   t i m e S t e p ) 
 { 
         c o n s t   d o u b l e   w a l k S p e e d   =   r e s o u r c e . W a l k S p e e d M e t e r s P e r S e c ( ) ; 
 
         i f   ( w a l k S p e e d   < =   0 )   { 
                 c e r r   < <   " E r r o r :   W a l k   s p e e d   i s   0 .   S e t   W a l k S p e e d   i n   A g e n t P r o f i l e . "   < <   e n d l ; 
                 e x i t ( 1 ) ; 
         } 
 
         c o n s t   d o u b l e   w a l k D i s t a n c e   =   w a l k S p e e d * ( d o u b l e ( t i m e S t e p ) / S E C O N D ) ; 
 
         r e m a i n i n g P a t h D i s t a n c e   =   s t d : : m a x < d o u b l e > ( 0 . ,   r e m a i n i n g P a t h D i s t a n c e   -   w a l k D i s t a n c e ) ; 
 
         V e r t e x   p o s i t i o n   =   C a l c u l a t e N e x t V e r t e x ( n e x t P o s ,   d i r e c t i o n V e c t o r ,   r e m a i n i n g P a t h D i s t a n c e ) ; 
         p o s i t i o n . z   =   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) . G e t G r o u n d E l e v a t i o n M e t e r s A t ( p o s i t i o n ) ; 
 
         r e s o u r c e . S e t P o s i t i o n ( p o s i t i o n ) ; 
 
         i f   ( ( * t h i s ) . H a s F i n i s h e d ( ) )   { 
                 i f   ( e n t e r T o P o s i t i o n )   { 
                         r e s o u r c e . A r r i v e d A t D e s t i n a t i o n N o t i f i c a t i o n ( ) ; 
                 }   e l s e   { 
                         r e s o u r c e . S e t D e s i r e d N e x t P o s i t i o n I d ( e n d P o s i t i o n I d ) ; 
                 } 
                 r e s o u r c e . S e t E x t r a P o i I d ( e x t r a D e s t P o i n I d ) ; 
         } 
 } 
 
 
 
 v o i d   F r e e W a l k B e h a v i o r : : E n d B e h a v i o r A t V i a P o i n t ( c o n s t   s h a r e d _ p t r < A g e n t R o u t e > &   n e x t R o u t e P t r ) 
 { 
         i f   ( n e x t R o u t e P t r   = =   n u l l p t r )   { 
                 r e t u r n ; 
         } 
 
         c o n s t   V e r t e x &   c u r r e n t P o s   =   r e s o u r c e . P o s i t i o n ( ) ; 
 
         e n t e r T o P o s i t i o n   =   f a l s e ; 
 
         e n d P o s i t i o n I d   =   G i s P o s i t i o n I d T y p e ( G I S _ R O A D ,   n e x t R o u t e P t r - > G e t F r o n t R o a d I d ( ) ) ; 
         e x t r a D e s t P o i n I d   =   U N R E A C H A B L E _ P O S I T I O N _ I D ; 
 
         n e x t P o s   =   t h e A g e n t G i s P t r - > G e t V e r t e x ( r e s o u r c e . L a s t V e r t e x I d ( ) ) ; 
 
         d i r e c t i o n V e c t o r   =   ( n e x t P o s   -   c u r r e n t P o s ) . N o r m a l i z e d ( ) ; 
         r e m a i n i n g P a t h D i s t a n c e   =   c u r r e n t P o s . D i s t a n c e T o ( n e x t P o s ) ; 
 
         r e s o u r c e . S e t D i r e c t i o n R a d i a n s ( d i r e c t i o n V e c t o r . D i r e c t i o n R a d i a n s ( ) ) ; 
 } 
 
 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 / /   P e d e s t r i a n 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 P e d e s t r i a n B e h a v i o r : : P e d e s t r i a n B e h a v i o r ( 
         c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   i n i t A g e n t G i s P t r , 
         c o n s t   s h a r e d _ p t r < P u b l i c V e h i c l e T a b l e > &   i n i t P u b l i c V e h i c l e T a b l e P t r , 
         c o n s t   s h a r e d _ p t r < A g e n t R o u t e > &   i n i t R o u t e P t r , 
         c o n s t   A g e n t R e s o u r c e &   i n i t R e s o u r c e ) 
         : 
         A g e n t B e h a v i o r ( i n i t A g e n t G i s P t r ,   i n i t P u b l i c V e h i c l e T a b l e P t r ,   i n i t R o u t e P t r ,   i n i t R e s o u r c e ) , 
         s t a t e ( S T A T E _ W A L K _ R O A D S I D E ) , 
         n e x t P o s ( r e s o u r c e . P o s i t i o n ( ) ) , 
         r o a d I d ( I N V A L I D _ V A R I A N T _ I D ) , 
         n e x t V e r t e x I d ( r e s o u r c e . L a s t V e r t e x I d ( ) ) , 
         r e m a i n i n g P a t h D i s t a n c e ( 0 ) , 
         c r o s s i n g D i r e c t i o n I s C l o c k w i s e ( t r u e ) , 
         i s C u r r e n t L e f t S i d e ( t r u e ) , 
         i s C r o s s i n g R o a d A V e h i c l e R o a d ( f a l s e ) , 
         c u r r e n t V e r t e x N u m b e r ( 0 ) , 
         c u r r e n t R o u t e N u m b e r ( 0 ) , 
         c u r r e n t W a l k S t a r t T i m e ( Z E R O _ T I M E ) , 
         p e d e s t r i a n R o a d W a l k O f f s e t R a t i o ( r e s o u r c e . G e t R a n d o m N u m b e r G e n e r a t o r ( ) . G e n e r a t e R a n d o m D o u b l e ( )   -   0 . 5 ) , 
         e n d B e h a v i o r A t V i a P o i n t ( f a l s e ) 
 { 
         ( * t h i s ) . R e s e t D e s t i n a t i o n P o s i t i o n ( ) ; 
 
         ( * t h i s ) . U p d a t e N e x t W a l k P a t h ( ) ; 
 } 
 
 P e d e s t r i a n B e h a v i o r : : P e d e s t r i a n B e h a v i o r ( 
         c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   i n i t A g e n t G i s P t r , 
         c o n s t   s h a r e d _ p t r < P u b l i c V e h i c l e T a b l e > &   i n i t P u b l i c V e h i c l e T a b l e P t r , 
         c o n s t   s h a r e d _ p t r < A g e n t R o u t e > &   i n i t R o u t e P t r , 
         c o n s t   V e r t e x &   i n i t D e s t P o s , 
         c o n s t   A g e n t R e s o u r c e &   i n i t R e s o u r c e ) 
         : 
         A g e n t B e h a v i o r ( i n i t A g e n t G i s P t r ,   i n i t P u b l i c V e h i c l e T a b l e P t r ,   i n i t R o u t e P t r ,   i n i t R e s o u r c e ) , 
         s t a t e ( S T A T E _ W A L K _ R O A D S I D E ) , 
         n e x t P o s ( r e s o u r c e . P o s i t i o n ( ) ) , 
         d e s t P o s ( i n i t D e s t P o s ) , 
         r o a d I d ( I N V A L I D _ V A R I A N T _ I D ) , 
         n e x t V e r t e x I d ( r e s o u r c e . L a s t V e r t e x I d ( ) ) , 
         r e m a i n i n g P a t h D i s t a n c e ( 0 ) , 
         c r o s s i n g D i r e c t i o n I s C l o c k w i s e ( t r u e ) , 
         i s C u r r e n t L e f t S i d e ( t r u e ) , 
         i s C r o s s i n g R o a d A V e h i c l e R o a d ( f a l s e ) , 
         c u r r e n t V e r t e x N u m b e r ( 0 ) , 
         c u r r e n t R o u t e N u m b e r ( 0 ) , 
         c u r r e n t W a l k S t a r t T i m e ( Z E R O _ T I M E ) , 
         p e d e s t r i a n R o a d W a l k O f f s e t R a t i o ( r e s o u r c e . G e t R a n d o m N u m b e r G e n e r a t o r ( ) . G e n e r a t e R a n d o m D o u b l e ( )   -   0 . 5 ) , 
         e n d B e h a v i o r A t V i a P o i n t ( f a l s e ) 
 { 
         ( * t h i s ) . U p d a t e N e x t W a l k P a t h ( ) ; 
 } 
 
 
 
 v o i d   P e d e s t r i a n B e h a v i o r : : U p d a t e N e x t W a l k P a t h ( ) 
 { 
         V e r t e x   c u r r e n t P o s   =   r e s o u r c e . P o s i t i o n ( ) ; 
         c o n s t   G i s S u b s y s t e m &   s u b s y s t e m   =   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) ; 
 
         i f   ( c r o s s i n g O r R o a d s i d e W a l k s . e m p t y ( ) )   { 
 
                 i f   ( s t a t e   = =   S T A T E _ C R O S S I N G _ R O A D )   { 
 
                         i s C u r r e n t L e f t S i d e   =   c r o s s i n g D i r e c t i o n I s C l o c k w i s e ; 
                         t h e A g e n t G i s P t r - > S e t L e a v e P e o p l e ( r o a d I d ,   r e s o u r c e ) ; 
 
                 }   e l s e   i f   ( c u r r e n t V e r t e x N u m b e r   = =   c u r r e n t W a y p o i n t s . s i z e ( )   & & 
                                       c u r r e n t R o u t e N u m b e r   <   r o u t e P t r - > r o a d R o u t e s . s i z e ( ) )   { 
 
                         c o n s t   R o a d R o u t e &   r o a d R o u t e   =   r o u t e P t r - > r o a d R o u t e s [ c u r r e n t R o u t e N u m b e r ] ; 
                         c o n s t   A g e n t R o a d &   a g e n t R o a d   =   t h e A g e n t G i s P t r - > G e t A g e n t R o a d ( r o a d R o u t e . r o a d I d ) ; 
                         c o n s t   d o u b l e   c o n g e s t i o n   =   a g e n t R o a d . C a l c u l a t e P e o p l e C o n g e s t i o n ( ) ; 
                         c o n s t   A g e n t I n t e r s e c t i o n &   i n t e r s e c t i o n   = 
                                 t h e A g e n t G i s P t r - > G e t A g e n t I n t e r s e c t i o n ( s u b s y s t e m . G e t I n t e r s e c t i o n I d ( n e x t V e r t e x I d ) ) ; 
 
                         i f   ( ( r e s o u r c e . A g e n t I d ( )   = =   1 )   | |   ( r e s o u r c e . A g e n t I d ( )   = =   1 9 ) ) { 
                                 c o u t   < <   " A g e n t   "   < <   r e s o u r c e . A g e n t I d ( )   < <   "   b e h a v i o r   n e x t v e r t e x   "   < <   n e x t V e r t e x I d   < <   e n d l ; 
                         } 
 
                         r e s o u r c e . S e t C o n g e s t i o n ( c o n g e s t i o n ) ; 
                         r e s o u r c e . S e t V e r t e x I d ( n e x t V e r t e x I d ) ; 
 
                         i f   ( e n d B e h a v i o r A t V i a P o i n t )   { 
                                 ( * t h i s ) . F o r c e S t o p W a l k ( ) ; 
                                 r e t u r n ; 
                         } 
 
                         i f   ( ! a g e n t R o a d . G e t G i s R o a d ( ) . I s E n a b l e d ( ) )   { 
                                 r e s o u r c e . A r r i v e d A t D e a d E n d N o t i f i c a t i o n ( ) ; 
                                 ( * t h i s ) . F o r c e S t o p W a l k ( ) ; 
                                 r e s o u r c e . R e c a l c u l a t e R o u t e ( ) ; 
                                 r e t u r n ; 
                         } 
 
                         i f   ( r e s o u r c e . I s P a t h Q u e r y T r i g g e r A v a i l a b l e ( c o n g e s t i o n ) )   { 
                                 ( * t h i s ) . F o r c e S t o p W a l k ( ) ; 
                                 r e s o u r c e . R e c a l c u l a t e R o u t e ( ) ; 
                                 r e s o u r c e . S e t L a s t P a t h Q u e r y T r i g g e r T i m e ( ) ; 
                                 r e t u r n ; 
                         } 
 
                         i f   ( ! r e s o u r c e . I s D i s a s t e r M o d e ( )   & & 
                                 ! i n t e r s e c t i o n . r e f . P e d e s t r i a n C a n P a s s ( ) )   { 
                                 i n t e r s e c t i o n . G e t C r o s s i n g O r S i d e W a l k R o a d I d s ( 
                                         * t h e A g e n t G i s P t r , 
                                         r o a d I d , 
                                         r o a d R o u t e . r o a d I d , 
                                         i s C u r r e n t L e f t S i d e , 
                                         c r o s s i n g D i r e c t i o n I s C l o c k w i s e , 
                                         c r o s s i n g O r R o a d s i d e W a l k s , 
                                         c u r r e n t W a y p o i n t s , 
                                         r e s o u r c e . G e t R a n d o m N u m b e r G e n e r a t o r ( ) ) ; 
 
                                 c u r r e n t V e r t e x N u m b e r   =   0 ; 
                         } 
                 } 
         } 
 
         i f   ( ! c r o s s i n g O r R o a d s i d e W a l k s . e m p t y ( ) )   { 
                 s t a t e   =   S T A T E _ C R O S S I N G _ R O A D ; 
 
                 c o n s t   p a i r < R o a d I d T y p e ,   b o o l > &   c r o s s i n g O r R o a d s i d e W a l k   =   c r o s s i n g O r R o a d s i d e W a l k s . f r o n t ( ) ; 
 
                 r o a d I d   =   c r o s s i n g O r R o a d s i d e W a l k . f i r s t ; 
                 r e s o u r c e . S e t D e s i r e d N e x t P o s i t i o n I d ( G i s P o s i t i o n I d T y p e ( G I S _ R O A D ,   r o a d I d ) ) ; 
 
                 a s s e r t ( r o a d I d   ! =   I N V A L I D _ V A R I A N T _ I D ) ; 
 
                 i s C r o s s i n g R o a d A V e h i c l e R o a d   =   f a l s e ; 
 
                 / /   i s   c r o s s i n g 
                 i f   ( c r o s s i n g O r R o a d s i d e W a l k . s e c o n d )   { 
                         c o n s t   A g e n t R o a d &   a g e n t R o a d   =   t h e A g e n t G i s P t r - > G e t A g e n t R o a d ( r o a d I d ) ; 
 
                         i s C r o s s i n g R o a d A V e h i c l e R o a d   =   a g e n t R o a d . G e t G i s R o a d ( ) . V e h i c l e C a n P a s s ( ) ; 
 
                         i f   ( i s C r o s s i n g R o a d A V e h i c l e R o a d )   { 
                                 c o n s t   A g e n t I n t e r s e c t i o n &   i n t e r s e c t i o n   = 
                                         t h e A g e n t G i s P t r - > G e t A g e n t I n t e r s e c t i o n ( 
                                                 s u b s y s t e m . G e t I n t e r s e c t i o n I d ( r e s o u r c e . L a s t V e r t e x I d ( ) ) ) ; 
 
                                 c u r r e n t W a l k S t a r t T i m e   = 
                                         i n t e r s e c t i o n . r e f . C a l c u l a t e C r o s s i n g S t a r t T i m e ( 
                                                 r e s o u r c e . C u r r e n t T i m e ( ) , 
                                                 r o a d I d , 
                                                 c r o s s i n g D i r e c t i o n I s C l o c k w i s e , 
                                                 s t a t i c _ c a s t < S i m T i m e > ( a g e n t R o a d . G e t G i s R o a d ( ) . G e t R o a d W i d t h M e t e r s ( )   /   ( * t h i s ) . G e t A g e n t S p e e d ( ) )   *   S E C O N D ) ; 
                         } 
                 } 
 
                 c r o s s i n g O r R o a d s i d e W a l k s . p o p _ f r o n t ( ) ; 
 
         }   e l s e   { 
 
                 c o n s t   b o o l   c r o s s e d R o a d   =   ( s t a t e   = =   S T A T E _ C R O S S I N G _ R O A D ) ; 
 
                 s t a t e   =   S T A T E _ W A L K _ R O A D S I D E ; 
 
                 i f   ( c u r r e n t V e r t e x N u m b e r   = =   c u r r e n t W a y p o i n t s . s i z e ( )   & & 
                         c u r r e n t R o u t e N u m b e r   <   r o u t e P t r - > r o a d R o u t e s . s i z e ( ) )   { 
 
                         c o n s t   R o a d R o u t e &   r o a d R o u t e   =   r o u t e P t r - > r o a d R o u t e s [ c u r r e n t R o u t e N u m b e r ] ; 
                         n e x t V e r t e x I d   =   r o a d R o u t e . n e x t V e r t e x I d ; 
 
                         c o n s t   A g e n t R o a d &   a g e n t R o a d   =   t h e A g e n t G i s P t r - > G e t A g e n t R o a d ( r o a d R o u t e . r o a d I d ) ; 
 
                         i f   ( ( r e s o u r c e . A g e n t I d ( )   = =   1 )   | |   ( r e s o u r c e . A g e n t I d ( )   = =   1 9 ) ) { 
                                 c o u t     < <   " A g e n t   "   < <   r e s o u r c e . A g e n t I d ( )   < <   "   b e h a v i o r 3 0 1   n e x t v e r t e x   "   < <   n e x t V e r t e x I d   < <   e n d l ; 
                                 c o u t     < <   " A g e n t   "   < <   r e s o u r c e . A g e n t I d ( )   < <   "   r e s o u r c e L a s t V e r t   "   < <   r e s o u r c e . L a s t V e r t e x I d ( )   < <   e n d l ; 
                         } 
 
 
                         i f   ( r e s o u r c e . I s D i s a s t e r M o d e ( )   | |   a g e n t R o a d . G e t G i s R o a d ( ) . I s P e d e s t r i a n R o a d ( ) )   { 
                                 c o n s t   d o u b l e   r o a d W i d t h   =   a g e n t R o a d . G e t G i s R o a d ( ) . G e t R o a d W i d t h M e t e r s ( ) ; 
                                 a g e n t R o a d . G e t G i s R o a d ( ) . G e t P e d e s t r i a n V e r t i c e s ( n e x t V e r t e x I d ,   r e s o u r c e . L a s t V e r t e x I d ( ) ,   i s C u r r e n t L e f t S i d e ,   r o a d W i d t h * p e d e s t r i a n R o a d W a l k O f f s e t R a t i o ,   c u r r e n t P o s ,   c u r r e n t W a y p o i n t s ) ; 
 
                         }   e l s e   { 
                                 a g e n t R o a d . G e t G i s R o a d ( ) . G e t P e d e s t r i a n V e r t i c e s ( n e x t V e r t e x I d ,   r e s o u r c e . L a s t V e r t e x I d ( ) ,   i s C u r r e n t L e f t S i d e ,   c u r r e n t P o s ,   c u r r e n t W a y p o i n t s ) ; 
                         } 
 
                         / /   a d j u s t   z   t o   f i r s t   p o s i t i o n 
                         d o u b l e   a d j u s t Z   =   c u r r e n t P o s . z ; 
 
                         i f   ( ! c u r r e n t W a y p o i n t s . e m p t y ( ) )   { 
                                 a d j u s t Z   =   c u r r e n t W a y p o i n t s . f r o n t ( ) . z ; 
                         } 
                         / /   s m o o t h   c o r r e c t i o n   t o   n e x t   p o i n t 
                         i f   ( ! c u r r e n t W a y p o i n t s . e m p t y ( ) )   { 
                                 i f   ( c r o s s e d R o a d   | |   a g e n t R o a d . G e t G i s R o a d ( ) . I s E x t r a P a t h ( ) )   { 
                                         c u r r e n t W a y p o i n t s . p o p _ f r o n t ( ) ; 
                                 } 
                         } 
 
                         / /   p u t   a d j u s t e d   p o s i t i o n 
                         i f   ( c u r r e n t P o s . z   ! =   a d j u s t Z )   { 
                                 c u r r e n t W a y p o i n t s . p u s h _ f r o n t ( V e r t e x ( c u r r e n t P o s . x ,   c u r r e n t P o s . y ,   a d j u s t Z ) ) ; 
                         } 
 
                         / /   s m o o t h   c o r r e c t i o n   t o   n e x t - n e x t   p o i n t 
                         i f   ( ! c u r r e n t W a y p o i n t s . e m p t y ( )   & & 
                                 c u r r e n t R o u t e N u m b e r   +   1   <   r o u t e P t r - > r o a d R o u t e s . s i z e ( ) )   { 
 
                                 c o n s t   R o a d R o u t e &   n e x t R o u t e   =   r o u t e P t r - > r o a d R o u t e s [ c u r r e n t R o u t e N u m b e r   +   1 ] ; 
                                 c o n s t   A g e n t I n t e r s e c t i o n &   i n t e r s e c t i o n   = 
                                         t h e A g e n t G i s P t r - > G e t A g e n t I n t e r s e c t i o n ( s u b s y s t e m . G e t I n t e r s e c t i o n I d ( n e x t V e r t e x I d ) ) ; 
 
                                 i f   ( ! r e s o u r c e . I s D i s a s t e r M o d e ( )   & & 
                                         ! i n t e r s e c t i o n . r e f . P e d e s t r i a n C a n P a s s ( ) )   { 
                                         d e q u e < V e r t e x >   n e x t W a y p o i n t s ; 
                                         b o o l   i s N e x t C r o s s i n g D i r e c t i o n C l o c k w i s e ; 
                                         l i s t < p a i r < R o a d I d T y p e ,   b o o l >   >   n e x t C r o s s i n g O r R o a d s i d e W a l k s ; 
 
                                         i n t e r s e c t i o n . G e t C r o s s i n g O r S i d e W a l k R o a d I d s ( 
                                                 * t h e A g e n t G i s P t r , 
                                                 r o a d R o u t e . r o a d I d , 
                                                 n e x t R o u t e . r o a d I d , 
                                                 i s C u r r e n t L e f t S i d e , 
                                                 i s N e x t C r o s s i n g D i r e c t i o n C l o c k w i s e , 
                                                 n e x t C r o s s i n g O r R o a d s i d e W a l k s , 
                                                 n e x t W a y p o i n t s , 
                                                 r e s o u r c e . G e t R a n d o m N u m b e r G e n e r a t o r ( ) ) ; 
 
                                         i f   ( ! n e x t W a y p o i n t s . e m p t y ( ) )   { 
                                                 c u r r e n t W a y p o i n t s . b a c k ( )   =   n e x t W a y p o i n t s . f r o n t ( ) ; 
                                         } 
                                 } 
                         } 
 
                         c u r r e n t R o u t e N u m b e r + + ; 
                         c u r r e n t V e r t e x N u m b e r   =   0 ; 
 
                         r o a d I d   =   r o a d R o u t e . r o a d I d ; 
 
                         r e s o u r c e . S e t D e s i r e d N e x t P o s i t i o n I d ( G i s P o s i t i o n I d T y p e ( G I S _ R O A D ,   r o a d I d ) ) ; 
                 } 
         } 
 
         i f   ( c u r r e n t V e r t e x N u m b e r   <   c u r r e n t W a y p o i n t s . s i z e ( ) )   { 
 
                 n e x t P o s   =   c u r r e n t W a y p o i n t s [ c u r r e n t V e r t e x N u m b e r ] ; 
                 c u r r e n t V e r t e x N u m b e r + + ; 
 
         }   e l s e   i f   ( c u r r e n t R o u t e N u m b e r   > =   r o u t e P t r - > r o a d R o u t e s . s i z e ( ) )   { 
                 i f   ( ! r o u t e P t r - > I s E m p t y ( ) )   { 
                         r e s o u r c e . S e t V e r t e x I d ( r o u t e P t r - > r o a d R o u t e s . b a c k ( ) . n e x t V e r t e x I d ) ; 
                 } 
                 n e x t P o s   =   d e s t P o s ; 
         } 
 
         d i r e c t i o n V e c t o r   =   ( n e x t P o s   -   c u r r e n t P o s ) . N o r m a l i z e d ( ) ; 
         r e m a i n i n g P a t h D i s t a n c e   =   c u r r e n t P o s . D i s t a n c e T o ( n e x t P o s ) ; 
         r e s o u r c e . S e t D i r e c t i o n R a d i a n s ( d i r e c t i o n V e c t o r . D i r e c t i o n R a d i a n s ( ) ) ; 
 } 
 
 
 
 
 v o i d   P e d e s t r i a n B e h a v i o r : : I n c r e m e n t T i m e S t e p ( c o n s t   S i m T i m e &   t i m e S t e p ) 
 { 
         S i m T i m e   r e m a i n i n g T i m e   =   t i m e S t e p ; 
 
         w h i l e   ( ! ( * t h i s ) . H a s F i n i s h e d ( )   & &   r e m a i n i n g T i m e   >   Z E R O _ T I M E )   { 
                 ( * t h i s ) . I n c r e m e n t T i m e S t e p ( t i m e S t e p ,   r e m a i n i n g T i m e ) ; 
         } 
 
         c o n s t   V e r t e x   p o s i t i o n   =   C a l c u l a t e N e x t V e r t e x ( n e x t P o s ,   d i r e c t i o n V e c t o r ,   r e m a i n i n g P a t h D i s t a n c e ) ; 
 
         r e s o u r c e . S e t P o s i t i o n ( p o s i t i o n ) ; 
 } 
 
 
 
 
 v o i d   P e d e s t r i a n B e h a v i o r : : I n c r e m e n t T i m e S t e p ( c o n s t   S i m T i m e &   t i m e S t e p ,   S i m T i m e &   r e m a i n i n g T i m e ) 
 { 
         c o n s t   S i m T i m e   c u r r e n t T i m e   =   r e s o u r c e . C u r r e n t T i m e ( ) ; 
 
         r e m a i n i n g T i m e   =   s t d : : m a x ( Z E R O _ T I M E ,   s t d : : m i n ( c u r r e n t T i m e   -   c u r r e n t W a l k S t a r t T i m e ,   t i m e S t e p ) ) ; 
 
         i f   ( r e m a i n i n g T i m e   = =   Z E R O _ T I M E )   { 
                 i f   ( s t a t e   = =   S T A T E _ C R O S S I N G _ R O A D )   { 
                         t h e A g e n t G i s P t r - > S e t W a i t i n g P e o p l e ( r o a d I d ,   r e s o u r c e ) ; 
                 } 
                 r e t u r n ; 
         } 
 
         d o u b l e   w a l k S p e e d M e t e r s P e r S e c   =   G e t A g e n t S p e e d ( ) ; 
 
         i f   ( w a l k S p e e d M e t e r s P e r S e c   < =   0 )   { 
                 c e r r   < <   " E r r o r :   W a l k   s p e e d   i s   0 .   S e t   W a l k S p e e d   i n   A g e n t P r o f i l e . "   < <   e n d l ; 
                 e x i t ( 1 ) ; 
         } 
 
         i f   ( ( s t a t e   = =   S T A T E _ W A L K _ R O A D S I D E )   & &   ( r o a d I d   ! =   I N V A L I D _ V A R I A N T _ I D ) )   { 
 
                 c o n s t   A g e n t R o a d &   a g e n t R o a d   =   t h e A g e n t G i s P t r - > G e t A g e n t R o a d ( r o a d I d ) ; 
                 c o n s t   d o u b l e   d e n s i t y   =   a g e n t R o a d . C a l c u l a t e P e o p l e C o n g e s t i o n ( ) ; 
                 / / c o n s t   d o u b l e   d e n s i t y   =   a g e n t R o a d . C a l c u l a t e P e o p l e C o n g e s t i o n W i t h o u t ( r e s o u r c e ) ; 
                 c o n s t   d o u b l e   m i n P e d e s t r i a n S p e e d M e t e r s P e r S e c   =   1 ; 
                 w a l k S p e e d M e t e r s P e r S e c   = 
                         s t d : : m a x ( w a l k S p e e d M e t e r s P e r S e c   *   ( 1   -   d e n s i t y ) ,   m i n P e d e s t r i a n S p e e d M e t e r s P e r S e c ) ; 
         } 
 
         c o n s t   d o u b l e   w a l k D i s t a n c e   =   w a l k S p e e d M e t e r s P e r S e c * ( d o u b l e ( r e m a i n i n g T i m e ) / S E C O N D ) ; 
 
         i f   ( r e s o u r c e . A g e n t I d ( )   = =   1 9 )   { 
                 c o u t   < <   " r e m a i n i n g P a t h D i s t a n c e   i s   "   < <   r e m a i n i n g P a t h D i s t a n c e   < <   "   T i m e : "   < <   C o n v e r t T i m e T o D o u b l e S e c s ( c u r r e n t T i m e )   < <   e n d l ; 
                 c o u t   < <   " w a l k D i s t a n c e "   < <   w a l k D i s t a n c e   < <   e n d l ; 
 
                 i f   ( r e s o u r c e . C h a n g e d B y M e e t i n g ( )   = =   t r u e ) { 
                         c o u t   < <   " I n   b e h a v i o r   s u c c e e d "   < <   e n d l ; 
                 } 
         } 
 
         i f   ( r e m a i n i n g P a t h D i s t a n c e   < =   w a l k D i s t a n c e )   { 
                 i f   ( n e x t P o s   ! =   d e s t P o s )   { 
 
                         r e m a i n i n g T i m e   + =   s t a t i c _ c a s t < S i m T i m e > ( 
                                 ( ( w a l k D i s t a n c e   -   r e m a i n i n g P a t h D i s t a n c e )   /   w a l k S p e e d M e t e r s P e r S e c )   *   S E C O N D ) ; 
 
                         ( * t h i s ) . U p d a t e N e x t W a l k P a t h ( ) ; 
                 }   e l s e   { 
                         i f   ( ! r o u t e P t r - > I s E m p t y ( ) )   { 
                                 r e s o u r c e . S e t V e r t e x I d ( r o u t e P t r - > r o a d R o u t e s . b a c k ( ) . n e x t V e r t e x I d ) ; 
                         } 
 
                         c u r r e n t R o u t e N u m b e r   =   r o u t e P t r - > r o a d R o u t e s . s i z e ( ) ; 
                         r e m a i n i n g P a t h D i s t a n c e   =   0 ; 
                         r e m a i n i n g T i m e   =   Z E R O _ T I M E ; 
                 } 
 
         }     e l s e   i f   ( r e s o u r c e . C h a n g e d B y M e e t i n g ( ) ) { 
 
                         c o u t   < <   " A g e n t "   < <   r e s o u r c e . A g e n t I d ( )   < <   "   c h a n g e d b y   m e e t i n g   i s   t r u e "   < <   e n d l ; 
                         i f   ( n e x t P o s   ! =   d e s t P o s )   { 
 
                         r e m a i n i n g T i m e   + =   s t a t i c _ c a s t < S i m T i m e > ( 
                                 ( ( w a l k D i s t a n c e   -   r e m a i n i n g P a t h D i s t a n c e )   /   w a l k S p e e d M e t e r s P e r S e c )   *   S E C O N D ) ; 
 
                         ( * t h i s ) . U p d a t e N e x t W a l k P a t h ( ) ; 
                 }   e l s e   { 
                         i f   ( ! r o u t e P t r - > I s E m p t y ( ) )   { 
                                 r e s o u r c e . S e t V e r t e x I d ( r o u t e P t r - > r o a d R o u t e s . b a c k ( ) . n e x t V e r t e x I d ) ; 
                         } 
 
                         c u r r e n t R o u t e N u m b e r   =   r o u t e P t r - > r o a d R o u t e s . s i z e ( ) ; 
                         r e m a i n i n g P a t h D i s t a n c e   =   0 ; 
                         r e m a i n i n g T i m e   =   Z E R O _ T I M E ; 
                 } 
 
                 }   e l s e   { 
                 r e m a i n i n g P a t h D i s t a n c e   - =   w a l k D i s t a n c e ; 
                 r e m a i n i n g T i m e   =   Z E R O _ T I M E ; 
 
                 i f   ( ( s t a t e   = =   S T A T E _ C R O S S I N G _ R O A D )   & &   ( i s C r o s s i n g R o a d A V e h i c l e R o a d ) )   { 
                         t h e A g e n t G i s P t r - > S e t C r o s s i n g P e o p l e ( r o a d I d ,   r e s o u r c e ) ; 
                 } 
         } 
 
         i f   ( r e m a i n i n g P a t h D i s t a n c e   < =   0 )   { 
                 r e m a i n i n g T i m e   =   Z E R O _ T I M E ; 
         } 
 } 
 
 
 
 v o i d   P e d e s t r i a n B e h a v i o r : : S t a r t M o v i n g T o N e w Q u e u e P o s i t i o n ( c o n s t   V e r t e x &   n e w Q u e u e P o s i t i o n ) 
 { 
         ( * t h i s ) . s t a t e   =   S T A T E _ Q U E U E D ; 
         ( * t h i s ) . q u e u e i n g S a v e d C u r r e n t P o s i t i o n   =   r e s o u r c e . P o s i t i o n ( ) ; 
         ( * t h i s ) . q u e u e i n g S a v e d N e x t P o s   =   n e x t P o s ; 
         ( * t h i s ) . n e x t P o s   =   n e w Q u e u e P o s i t i o n ; 
         a s s e r t ( n e x t P o s   ! =   d e s t P o s ) ; 
 
 } / / S t a r t M o v i n g T o N e w Q u e u e P o s i t i o n / / 
 
 
 v o i d   P e d e s t r i a n B e h a v i o r : : D e q u e u e ( ) 
 { 
         ( * t h i s ) . s t a t e   =   S T A T E _ W A L K _ R O A D S I D E ; 
 
         / /   " T e l e p o r t "   t o   p r e v i o u s l y   s a v e d   ( e n t r a n c e )   p o s i t i o n . 
 
         ( * t h i s ) . r e s o u r c e . S e t P o s i t i o n ( q u e u e i n g S a v e d C u r r e n t P o s i t i o n ) ; 
         ( * t h i s ) . n e x t P o s   =   q u e u e i n g S a v e d N e x t P o s ; 
 } 
 
 
 
 v o i d   P e d e s t r i a n B e h a v i o r : : E n d B e h a v i o r A t V i a P o i n t ( c o n s t   s h a r e d _ p t r < A g e n t R o u t e > &   n e x t R o u t e P t r ) 
 { 
         e n d B e h a v i o r A t V i a P o i n t   =   t r u e ; 
 } 
 
 
 
 V e r t e x I d T y p e   P e d e s t r i a n B e h a v i o r : : G e t V i a P o i n t V e r t e x I d ( )   c o n s t 
 { 
         i f   ( s t a t e   = =   S T A T E _ W A L K _ R O A D S I D E   & & 
                 0   <   c u r r e n t R o u t e N u m b e r   & &   c u r r e n t R o u t e N u m b e r   < =   r o u t e P t r - > r o a d R o u t e s . s i z e ( ) )   { 
 
                 c o n s t   R o a d R o u t e &   r o a d R o u t e   =   r o u t e P t r - > r o a d R o u t e s [ c u r r e n t R o u t e N u m b e r   -   1 ] ; 
 
                 r e t u r n   r o a d R o u t e . n e x t V e r t e x I d ; 
         } 
 
         r e t u r n   r e s o u r c e . L a s t V e r t e x I d ( ) ; 
 } 
 
 
 
 b o o l   P e d e s t r i a n B e h a v i o r : : I s A c c e p t a b l e R o u t e C h a n g e ( c o n s t   A g e n t R o u t e &   r o u t e )   c o n s t 
 { 
         r e t u r n   ( r o u t e . b e h a v i o r   = =   ( * t h i s ) . G e t B e h a v i o r T y p e ( ) ) ; 
 } 
 
 
 
 v o i d   P e d e s t r i a n B e h a v i o r : : C h a n g e R o u t e ( c o n s t   s h a r e d _ p t r < A g e n t R o u t e > &   n e w R o u t e P t r ) 
 { 
         i f   ( ( s t a t e   = =   S T A T E _ W A L K _ R O A D S I D E )   & & 
                 ( 0   <   c u r r e n t R o u t e N u m b e r   & &   c u r r e n t R o u t e N u m b e r   < =   r o u t e P t r - > r o a d R o u t e s . s i z e ( ) ) )   { 
 
                 c o n s t   R o a d R o u t e   l a s t R o a d R o u t e   =   r o u t e P t r - > r o a d R o u t e s [ c u r r e n t R o u t e N u m b e r   -   1 ] ; 
 
                 r o u t e P t r   =   n e w R o u t e P t r ; 
                 r o u t e P t r - > r o a d R o u t e s . p u s h _ f r o n t ( l a s t R o a d R o u t e ) ; 
                 c u r r e n t R o u t e N u m b e r   =   1 ; 
         }   e l s e   { 
                 r o u t e P t r   =   n e w R o u t e P t r ; 
                 c u r r e n t R o u t e N u m b e r   =   0 ; 
         } 
 
         e n d B e h a v i o r A t V i a P o i n t   =   f a l s e ; 
 
         ( * t h i s ) . R e s e t D e s t i n a t i o n P o s i t i o n ( ) ; 
 } 
 
 
 
 v o i d   P e d e s t r i a n B e h a v i o r : : R e s e t D e s t i n a t i o n P o s i t i o n ( ) 
 { 
         a s s e r t ( ! r o u t e P t r - > I s E m p t y ( ) ) ; 
 
         d e s t P o s   =   t h e A g e n t G i s P t r - > G e t V e r t e x ( r o u t e P t r - > r o a d R o u t e s . b a c k ( ) . n e x t V e r t e x I d ) ; 
 } 
 
 
 
 v o i d   P e d e s t r i a n B e h a v i o r : : F o r c e S t o p W a l k ( ) 
 { 
         r e m a i n i n g P a t h D i s t a n c e   =   0 ; 
 
         i f   ( e n d B e h a v i o r A t V i a P o i n t )   { 
                 c u r r e n t R o u t e N u m b e r   =   r o u t e P t r - > r o a d R o u t e s . s i z e ( ) ; 
         } 
 
         c r o s s i n g O r R o a d s i d e W a l k s . c l e a r ( ) ; 
 } 
 
 
 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 / /   B i c y c l e 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 B i c y c l e B e h a v i o r : : B i c y c l e B e h a v i o r ( 
         c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   i n i t A g e n t G i s P t r , 
         c o n s t   s h a r e d _ p t r < P u b l i c V e h i c l e T a b l e > &   i n i t P u b l i c V e h i c l e T a b l e P t r , 
         c o n s t   s h a r e d _ p t r < A g e n t R o u t e > &   i n i t R o u t e P t r , 
         c o n s t   A g e n t R e s o u r c e &   i n i t R e s o u r c e ) 
         : 
         P e d e s t r i a n B e h a v i o r ( i n i t A g e n t G i s P t r ,   i n i t P u b l i c V e h i c l e T a b l e P t r ,   i n i t R o u t e P t r ,   i n i t R e s o u r c e ) 
 { } 
 
 B i c y c l e B e h a v i o r : : B i c y c l e B e h a v i o r ( 
         c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   i n i t A g e n t G i s P t r , 
         c o n s t   s h a r e d _ p t r < P u b l i c V e h i c l e T a b l e > &   i n i t P u b l i c V e h i c l e T a b l e P t r , 
         c o n s t   s h a r e d _ p t r < A g e n t R o u t e > &   i n i t R o u t e P t r , 
         c o n s t   V e r t e x &   i n i t D e s t P o s , 
         c o n s t   A g e n t R e s o u r c e &   i n i t R e s o u r c e ) 
         : 
         P e d e s t r i a n B e h a v i o r ( i n i t A g e n t G i s P t r ,   i n i t P u b l i c V e h i c l e T a b l e P t r ,   i n i t R o u t e P t r ,   i n i t D e s t P o s ,   i n i t R e s o u r c e ) 
 { } 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 c o n s t   d o u b l e   V e h i c l e D r i v e r B e h a v i o r : : e n o u g h M i n D i s t a n c e   =   0 . 0 1 ;   / /   1 [ c m ] 
 c o n s t   d o u b l e   V e h i c l e D r i v e r B e h a v i o r : : l a n e C h a n g e T i m e S e c   =   5 ; 
 c o n s t   d o u b l e   V e h i c l e D r i v e r B e h a v i o r : : v e l o c i t y M a r g i n   =   0 ; 
 c o n s t   d o u b l e   V e h i c l e D r i v e r B e h a v i o r : : l a n e C h a n g e P r o h i b i t e d Z o n e L e n g t h   =   0 ; 
 c o n s t   d o u b l e   V e h i c l e D r i v e r B e h a v i o r : : f o r c e L a n e C h a n g e D i s t a n c e   =   5 0 ; 
 c o n s t   d o u b l e   V e h i c l e D r i v e r B e h a v i o r : : s l o w D o w n D i s t a n c e B e f o r e C u r v e   =   3 0 ; 
 
 V e h i c l e D r i v e r B e h a v i o r : : V e h i c l e D r i v e r B e h a v i o r ( 
         c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   i n i t A g e n t G i s P t r , 
         c o n s t   s h a r e d _ p t r < P u b l i c V e h i c l e T a b l e > &   i n i t P u b l i c V e h i c l e T a b l e P t r , 
         c o n s t   s h a r e d _ p t r < A g e n t R o u t e > &   i n i t R o u t e P t r , 
         c o n s t   A g e n t R e s o u r c e &   i n i t R e s o u r c e , 
         c o n s t   s h a r e d _ p t r < V e h i c l e > &   i n i t V e h i c l e P t r , 
         c o n s t   S i m T i m e &   i n i t M i n S h o r t S t o p T i m e ) 
         : 
         A g e n t B e h a v i o r ( i n i t A g e n t G i s P t r ,   i n i t P u b l i c V e h i c l e T a b l e P t r ,   i n i t R o u t e P t r ,   i n i t R e s o u r c e ) , 
         i s O n V e h i c l e ( f a l s e ) , 
         p a s s i n g I n t e r s e c t i o n ( f a l s e ) , 
         v e h i c l e P t r ( i n i t V e h i c l e P t r ) , 
         r e m a i n i n g D i s t a n c e T o I n t e r s e c t i o n ( 0 ) , 
         r e m a i n i n g S h o r t S t o p T i m e ( Z E R O _ T I M E ) , 
         m i n S h o r t S t o p T i m e ( i n i t M i n S h o r t S t o p T i m e ) , 
         l a n e C h a n g e E n a b l e T i m e ( Z E R O _ T I M E ) , 
         l a n e C h a n g e D i r e c t i o n ( 0 ) , 
         v e l o c i t y ( 0 . 0 ) , 
         c u r r e n t L a n e N u m b e r ( 0 ) , 
         r e m a i n i n g P a t h D i s t a n c e ( D B L _ M A X ) , 
         c u r r e n t W a y p o i n t R a d i a n s ( 0 ) , 
         v i e w d R o u t e N u m b e r ( 0 ) 
 { 
         v e h i c l e P t r - > S e t V e h i c l e C o n s t a n t ( r e s o u r c e . M a k e V e h i c l e C o n s t a n t ( ) ) ; 
 
         ( * t h i s ) . G o T o V e h i c l e ( ) ; 
 } 
 
 v o i d   V e h i c l e D r i v e r B e h a v i o r : : G o T o V e h i c l e ( ) 
 { 
         p e d e s t r i a n P t r . r e s e t ( 
                 n e w   P e d e s t r i a n B e h a v i o r ( 
                         t h e A g e n t G i s P t r , 
                         t h e P u b l i c V e h i c l e T a b l e P t r , 
                         s h a r e d _ p t r < A g e n t R o u t e > ( n e w   A g e n t R o u t e ( ) ) , 
                         v e h i c l e P t r - > G e t P o s i t i o n ( ) , 
                         r e s o u r c e ) ) ; 
 } 
 
 v o i d   V e h i c l e D r i v e r B e h a v i o r : : U p d a t e V i s i b l e R o u t e I f N e c e s s a r y ( ) 
 { 
         d o u b l e   v i s i b l e R o u t e D i s t a n c e   =   0 ; 
 
         i f   ( r o u t e s . e m p t y ( ) )   { 
                 v i s i b l e R o u t e D i s t a n c e   + =   r e m a i n i n g D i s t a n c e T o I n t e r s e c t i o n ; 
         } 
 
         f o r ( s i z e _ t   i   =   1 ;   i   <   r o u t e s . s i z e ( ) ;   i + + )   { 
                 v i s i b l e R o u t e D i s t a n c e   + = 
                         t h e A g e n t G i s P t r - > G e t A g e n t R o a d ( r o u t e s [ i ] . r o a d I d ) . G e t R o a d L e n g t h ( ) ; 
         } 
 
         c o n s t   d o u b l e   m a x V i s i b l e R o u t e D i s t a n c e   =   1 0 0 ; 
 
         w h i l e   ( ( v i s i b l e R o u t e D i s t a n c e   <   m a x V i s i b l e R o u t e D i s t a n c e )   & & 
                       v i e w d R o u t e N u m b e r   <   r o u t e P t r - > r o a d R o u t e s . s i z e ( ) )   { 
 
                 c o n s t   G i s S u b s y s t e m &   s u b s y s t e m   =   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) ; 
                 V e r t e x I d T y p e   l a s t V e r t e x I d ; 
 
                 i f   ( r o u t e s . e m p t y ( ) )   { 
                         l a s t V e r t e x I d   =   r e s o u r c e . L a s t V e r t e x I d ( ) ; 
                 }   e l s e   { 
                         l a s t V e r t e x I d   =   r o u t e s . b a c k ( ) . o u t g o i n g V e r t e x I d ; 
                 } 
 
                 c o n s t   R o a d R o u t e &   r o a d R o u t e   =   r o u t e P t r - > G e t R o a d R o u t e ( v i e w d R o u t e N u m b e r ) ; 
                 c o n s t   A g e n t R o a d &   n e x t R o a d   =   t h e A g e n t G i s P t r - > G e t A g e n t R o a d ( r o a d R o u t e . r o a d I d ) ; 
 
                 r o u t e s . p u s h _ b a c k ( V e h i c l e R o u t e ( ) ) ; 
                 V e h i c l e R o u t e &   n e x t R o u t e   =   r o u t e s [ r o u t e s . s i z e ( )   -   1 ] ; 
 
                 n e x t R o u t e . r o a d I d   =   r o a d R o u t e . r o a d I d ; 
 
                 n e x t R o u t e . o u t g o i n g V e r t e x I d   =   r o a d R o u t e . n e x t V e r t e x I d ; 
 
                 c o n s t   b o o l   a d d e d F o l l o w i n g R o u t e   =   ( r o u t e s . s i z e ( )   = =   2 ) ; 
 
                 i f   ( a d d e d F o l l o w i n g R o u t e )   { 
                         ( * t h i s ) . U p d a t e N e x t R o a d W a y p o i n t I f N e c e s s a r y ( ) ; 
                 } 
 
                 i f   ( r o u t e s . s i z e ( )   > =   2 )   { 
                         V e h i c l e R o u t e &   p r e v R o u t e   =   r o u t e s [ r o u t e s . s i z e ( )   -   2 ] ; 
 
                         c o n s t   I n t e r s e c t i o n &   i n t e r s e c t i o n   = 
                                 t h e A g e n t G i s P t r - > G e t A g e n t I n t e r s e c t i o n ( 
                                         s u b s y s t e m . G e t I n t e r s e c t i o n I d ( l a s t V e r t e x I d ) ) . r e f ; 
 
                         p r e v R o u t e . o u t g o i n g T u r n T y p e   = 
                                 i n t e r s e c t i o n . G e t R o a d T u r n T y p e ( p r e v R o u t e . r o a d I d ,   n e x t R o u t e . r o a d I d ) ; 
                 } 
 
                 v i s i b l e R o u t e D i s t a n c e   + =   n e x t R o a d . G e t R o a d L e n g t h ( ) ; 
 
                 v i e w d R o u t e N u m b e r + + ; 
         } 
 
         i f   ( ! r o u t e s . e m p t y ( ) )   { 
                 v e h i c l e P t r - > v i a p o i n t V e r t e x I d   =   r o u t e s . b a c k ( ) . o u t g o i n g V e r t e x I d ; 
         } 
 } 
 
 v o i d   V e h i c l e D r i v e r B e h a v i o r : : S e t N e x t W a y p o i n t ( ) 
 { 
         i f   ( r o u t e s . e m p t y ( ) )   { 
                 r e t u r n ; 
         } 
 
         a s s e r t ( ! r o u t e s . f r o n t ( ) . r e m a i n i n g W a y p o i n t s . e m p t y ( ) ) ; 
         c o n s t   V e r t e x   l a s t P o i n t   =   r o u t e s . f r o n t ( ) . r e m a i n i n g W a y p o i n t s . f r o n t ( ) ; 
 
         V e h i c l e R o u t e &   c u r r e n t R o u t e   =   r o u t e s . f r o n t ( ) ; 
 
         d o u b l e   e x t r a P a t h O f f s e t   =   0 . ; 
 
         c o n s t   R o a d &   c u r r e n t R o a d   =   t h e A g e n t G i s P t r - > G e t A g e n t R o a d ( c u r r e n t R o u t e . r o a d I d ) . G e t G i s R o a d ( ) ; 
 
         i f   ( c u r r e n t R o a d . I s E x t r a P a t h ( ) )   { 
                 / /   f o r c e   t r a n s i t i o n   f r o m   e x t r a ( s i m p l e   l i n e )   p a t h 
                 i f   ( r o u t e s . s i z e ( )   >   1 )   { 
                         e x t r a P a t h O f f s e t   = 
                                 t h e A g e n t G i s P t r - > G e t A g e n t R o a d ( r o u t e s [ 1 ] . r o a d I d ) . G e t G i s R o a d ( ) . G e t R o a d W i d t h M e t e r s ( ) * 0 . 5 ; 
                 } 
         } 
 
         i f   ( r e m a i n i n g D i s t a n c e T o I n t e r s e c t i o n   < =   e n o u g h M i n D i s t a n c e   +   e x t r a P a t h O f f s e t )   { 
 
                 V e h i c l e &   v e h i c l e   =   * v e h i c l e P t r ; 
 
                 c o n s t   V e r t e x I d T y p e   a r r i v e d V e r t e x I d   =   r o u t e s . f r o n t ( ) . o u t g o i n g V e r t e x I d ; 
                 c o n s t   R o a d I d T y p e   p r e v R o a d I d   =   c u r r e n t R o u t e . r o a d I d ; 
 
                 r o u t e s . p o p _ f r o n t ( ) ; 
 
                 r e s o u r c e . S e t V e r t e x I d ( a r r i v e d V e r t e x I d ) ; 
                 v e h i c l e P t r - > S e t N e x t V e r t e x I d ( a r r i v e d V e r t e x I d ) ; 
 
                 i f   ( ! r o u t e s . e m p t y ( ) )   { 
                         V e h i c l e R o u t e &   n e x t R o u t e   =   r o u t e s . f r o n t ( ) ; 
                         c o n s t   R o a d I d T y p e   n e x t R o a d I d   =   n e x t R o u t e . r o a d I d ; 
                         c o n s t   R o a d &   p r e v R o a d   =   t h e A g e n t G i s P t r - > G e t A g e n t R o a d ( p r e v R o a d I d ) . G e t G i s R o a d ( ) ; 
 
                         i f   ( ! p r e v R o a d . C a n A p p r o a c h ( c u r r e n t L a n e N u m b e r ,   r o u t e s . f r o n t ( ) . r o a d I d ) )   { 
                                 / /   f o r c e   c h a n g e   l a n e   f o m r   p a r k i n g 
                                 c u r r e n t L a n e N u m b e r   =   p r e v R o a d . G e t A p p r o a c h L a n e N u m b e r ( n e x t R o a d I d ) ; 
                         } 
 
                         c o n s t   A g e n t R o a d &   n e x t A g e n t R o a d   =   t h e A g e n t G i s P t r - > G e t A g e n t R o a d ( n e x t R o a d I d ) ; 
                         c o n s t   S i m T i m e   n o V e h i c l e D e l a y   =   Z E R O _ T I M E ; 
 
                         c u r r e n t L a n e N u m b e r   =   p r e v R o a d . G e t N e x t L a n e N u m b e r ( c u r r e n t L a n e N u m b e r ,   n e x t R o a d I d ) ; 
 
                         c o n s t   d o u b l e   c o n g e s t i o n   = 
                                 n e x t A g e n t R o a d . C a l c u l a t e V e h i c l e C o n g e s t i o n ( c u r r e n t L a n e N u m b e r ) ; 
 
                         a s s e r t ( ! n e x t A g e n t R o a d . G e t G i s R o a d ( ) . I s B u i l d i n g P a r k i n g R o a d ( ) ) ; 
 
 
                         i f   ( ( G e t B e h a v i o r T y p e ( )   = =   A G E N T _ B E H A V I O R _ V E H I C L E )   & & 
                                 ( p r e v R o a d . I s B u i l d i n g P a r k i n g R o a d ( ) ) )   { 
                                 c o n s t   B u i l d i n g I d T y p e   b u i l d i n g I d   =   p r e v R o a d . G e t B u i l d i n g I d ( ) ; 
 
                                 t h e A g e n t G i s P t r - > L e a v e F r o m P a r k i n g ( r e s o u r c e ,   b u i l d i n g I d ) ; 
                         } / / i f / / 
 
                         v e h i c l e . S e t N e x t L a n e N u m b e r ( c u r r e n t L a n e N u m b e r ) ; 
                         v e h i c l e . S e t N e x t R o a d I d ( n e x t R o u t e . r o a d I d ) ; 
                         v e h i c l e . S e t N e x t T u r n T y p e ( n e x t R o u t e . o u t g o i n g T u r n T y p e ) ; 
 
                         p a s s i n g I n t e r s e c t i o n   =   t r u e ; 
 
                         r e m a i n i n g D i s t a n c e T o I n t e r s e c t i o n   = 
                                 l a s t P o i n t . D i s t a n c e T o ( n e x t R o u t e . r e m a i n i n g W a y p o i n t s . f r o n t ( ) )   + 
                                 C a l c u l a t e A r c D i s t a n c e ( n e x t R o u t e . r e m a i n i n g W a y p o i n t s ) ; 
 
                         r e s o u r c e . S e t C o n g e s t i o n ( c o n g e s t i o n ) ; 
                         r e s o u r c e . S e t D e s i r e d N e x t P o s i t i o n I d ( G i s P o s i t i o n I d T y p e ( G I S _ R O A D ,   n e x t R o u t e . r o a d I d ) ) ; 
 
                         ( * t h i s ) . A r r i v e d A t V e r t e x ( a r r i v e d V e r t e x I d ) ; 
 
                         i f   ( ! n e x t A g e n t R o a d . G e t G i s R o a d ( ) . I s E n a b l e d ( ) )   { 
                                 r e s o u r c e . A r r i v e d A t D e a d E n d N o t i f i c a t i o n ( ) ; 
                                 ( * t h i s ) . F o r c e S t o p V e h i c l e ( ) ; 
                                 r e s o u r c e . R e c a l c u l a t e R o u t e ( ) ; 
                                 r e t u r n ; 
                         } 
 
                         i f   ( r e s o u r c e . I s P a t h Q u e r y T r i g g e r A v a i l a b l e ( c o n g e s t i o n ,   n o V e h i c l e D e l a y ) )   { 
                                 r e s o u r c e . R e c a l c u l a t e R o u t e ( ) ; 
                                 r e s o u r c e . S e t L a s t P a t h Q u e r y T r i g g e r T i m e ( ) ; 
                         } 
 
                         ( * t h i s ) . U p d a t e N e x t R o a d W a y p o i n t I f N e c e s s a r y ( ) ; 
 
                 }   e l s e   { 
                         ( * t h i s ) . A r r i v e d A t V e r t e x ( a r r i v e d V e r t e x I d ) ; 
                 } 
 
         }   e l s e   { 
                 c u r r e n t R o u t e . r e m a i n i n g W a y p o i n t s . p o p _ f r o n t ( ) ; 
                 p a s s i n g I n t e r s e c t i o n   =   f a l s e ; 
         } 
 
         i f   ( r o u t e s . e m p t y ( ) )   { 
                 r e m a i n i n g P a t h D i s t a n c e   =   0 ; 
                 r e t u r n ; 
         } 
 
         a s s e r t ( ! r o u t e s . f r o n t ( ) . r e m a i n i n g W a y p o i n t s . e m p t y ( ) ) ; 
         c o n s t   d e q u e < V e r t e x > &   c u r r e n t W a y p o i n t s   =   r o u t e s . f r o n t ( ) . r e m a i n i n g W a y p o i n t s ; 
 
         i f   ( c u r r e n t W a y p o i n t s . e m p t y ( ) )   { 
 
                 r e m a i n i n g P a t h D i s t a n c e   =   e n o u g h M i n D i s t a n c e ; 
 
         }   e l s e   { 
                 c o n s t   V e r t e x &   n e x t P o i n t   =   c u r r e n t W a y p o i n t s . f r o n t ( ) ; 
 
                 i f   ( l a s t P o i n t . D i s t a n c e T o ( n e x t P o i n t )   < =   e n o u g h M i n D i s t a n c e )   { 
 
                         r e m a i n i n g P a t h D i s t a n c e   =   e n o u g h M i n D i s t a n c e ; 
 
                 }   e l s e   { 
                         c o n s t   V e r t e x   p a t h V e c t o r   =   n e x t P o i n t   -   l a s t P o i n t ; 
 
                         d i r e c t i o n V e c t o r   =   p a t h V e c t o r . N o r m a l i z e d ( ) ; 
                         r e m a i n i n g P a t h D i s t a n c e   =   p a t h V e c t o r . D i s t a n c e ( ) ; 
 
                         v e h i c l e P t r - > S e t N e x t D i r e c t i o n R a d i a n s ( d i r e c t i o n V e c t o r . D i r e c t i o n R a d i a n s ( ) ) ; 
                         r e s o u r c e . S e t D i r e c t i o n R a d i a n s ( d i r e c t i o n V e c t o r . D i r e c t i o n R a d i a n s ( ) ) ; 
 
                         i f   ( c u r r e n t W a y p o i n t s . s i z e ( )   >   1 )   { 
 
                                 c u r r e n t W a y p o i n t R a d i a n s   =   C a l c u l a t e R a d i a n s B e t w e e n V e c t o r ( 
                                         l a s t P o i n t ,   n e x t P o i n t ,   c u r r e n t W a y p o i n t s [ 1 ] ) ; 
 
                         }   e l s e   i f   ( r o u t e s . s i z e ( )   >   1 )   { 
                                 a s s e r t ( ! r o u t e s [ 1 ] . r e m a i n i n g W a y p o i n t s . e m p t y ( ) ) ; 
 
                                 i f   ( r o u t e s [ 1 ] . r e m a i n i n g W a y p o i n t s . s i z e ( )   >   1 )   { 
                                         c u r r e n t W a y p o i n t R a d i a n s   =   C a l c u l a t e R a d i a n s B e t w e e n V e c t o r ( 
                                                 l a s t P o i n t , 
                                                 r o u t e s [ 1 ] . r e m a i n i n g W a y p o i n t s [ 0 ] , 
                                                 r o u t e s [ 1 ] . r e m a i n i n g W a y p o i n t s [ 1 ] ) ; 
                                 }   e l s e   { 
                                         c o n s t   V e r t e x I d T y p e   o u t g o i n g V e r t e x I d   =   r o u t e s . f r o n t ( ) . o u t g o i n g V e r t e x I d ; 
 
                                         c u r r e n t W a y p o i n t R a d i a n s   =   C a l c u l a t e R a d i a n s B e t w e e n V e c t o r ( 
                                                 l a s t P o i n t , 
                                                 t h e A g e n t G i s P t r - > G e t V e r t e x ( o u t g o i n g V e r t e x I d ) , 
                                                 r o u t e s [ 1 ] . r e m a i n i n g W a y p o i n t s . f r o n t ( ) ) ; 
                                 } 
                         } 
 
                         a s s e r t ( ! r o u t e s . e m p t y ( ) ) ; 
                         r e m a i n i n g D i s t a n c e T o I n t e r s e c t i o n   = 
                                 s t d : : m a x ( r e m a i n i n g D i s t a n c e T o I n t e r s e c t i o n ,   r e m a i n i n g P a t h D i s t a n c e ) ; 
                 } 
         } 
 } 
 
 v o i d   V e h i c l e D r i v e r B e h a v i o r : : A r r i v e d A t V e r t e x ( c o n s t   V e r t e x I d T y p e &   v e r t e x I d ) 
 { 
         i f   ( r o u t e s . e m p t y ( ) )   { 
                 / /   a r r i v e d   a t   t h e   d e s t i n a t i o n . 
 
                 ( * t h i s ) . P a r k i n g V e h i c l e I f P o s s i b l e ( v e r t e x I d ,   m i n S h o r t S t o p T i m e ) ; 
         } 
 } 
 
 v o i d   V e h i c l e D r i v e r B e h a v i o r : : P a r k i n g V e h i c l e I f P o s s i b l e ( 
         c o n s t   V e r t e x I d T y p e &   v e r t e x I d , 
         c o n s t   S i m T i m e &   s t o p T i m e ) 
 { 
         c o n s t   G i s S u b s y s t e m &   s u b s y s t e m   =   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) ; 
 
         i f   ( s u b s y s t e m . I s P a r k i n g V e r t e x ( v e r t e x I d ) )   { 
                 c o n s t   R o a d I d T y p e   r o a d I d   =   s u b s y s t e m . G e t P a r k i n g R o a d I d ( v e r t e x I d ) ; 
                 c o n s t   R o a d &   a R o a d   =   t h e A g e n t G i s P t r - > G e t A g e n t R o a d ( r o a d I d ) . G e t G i s R o a d ( ) ; 
 
                 v e h i c l e P t r - > S e t N e x t R o a d I d ( r o a d I d ) ; 
 
                 i f   ( ( G e t B e h a v i o r T y p e ( )   = =   A G E N T _ B E H A V I O R _ V E H I C L E )   & & 
                         ( a R o a d . I s B u i l d i n g P a r k i n g R o a d ( ) ) )   { 
 
                         c o n s t   B u i l d i n g I d T y p e   b u i l d i n g I d   =   a R o a d . G e t B u i l d i n g I d ( ) ; 
 
                       t h e A g e n t G i s P t r - > S t a r t V e h i c l e E n t r a n c e W a i t ( r e s o u r c e ,   b u i l d i n g I d ) ; 
                 } / / i f / / 
 
                 c u r r e n t L a n e N u m b e r   =   0 ; 
 
                 v e h i c l e P t r - > S e t N e x t L a n e N u m b e r ( c u r r e n t L a n e N u m b e r ) ; 
                 r e s o u r c e . S e t D e s i r e d N e x t P o s i t i o n I d ( G I S _ R O A D ,   r o a d I d ) ; 
                 r e m a i n i n g S h o r t S t o p T i m e   + =   s t o p T i m e ; 
         } 
 } 
 
 v o i d   V e h i c l e D r i v e r B e h a v i o r : : I n c r e m e n t T i m e S t e p ( c o n s t   S i m T i m e &   t i m e S t e p ) 
 { 
         V e h i c l e &   v e h i c l e   =   * v e h i c l e P t r ; 
 
         i f   ( ! i s O n V e h i c l e )   { 
                 i f   ( p e d e s t r i a n P t r   ! =   n u l l p t r )   { 
                         p e d e s t r i a n P t r - > I n c r e m e n t T i m e S t e p ( t i m e S t e p ) ; 
 
                         i f   ( p e d e s t r i a n P t r - > H a s F i n i s h e d ( ) )   { 
                                 ( * t h i s ) . R i d e O n V e h i c l e ( ) ; 
                         } 
                 } 
 
                 r e t u r n ; 
         } 
 
         S i m T i m e   r u n T i m e   =   t i m e S t e p ; 
 
         i f   ( r e m a i n i n g S h o r t S t o p T i m e   >   Z E R O _ T I M E )   { 
 
                 i f   ( r e m a i n i n g S h o r t S t o p T i m e   < =   r u n T i m e )   { 
                         r u n T i m e   - =   r e m a i n i n g S h o r t S t o p T i m e ; 
                         r e m a i n i n g S h o r t S t o p T i m e   =   Z E R O _ T I M E ; 
 
                         ( * t h i s ) . R e s t a r t R u n ( ) ; 
 
                 }   e l s e   { 
                         r e m a i n i n g S h o r t S t o p T i m e   - =   r u n T i m e ; 
                         r u n T i m e   =   Z E R O _ T I M E ; 
                 } 
         } 
 
         i f   ( r u n T i m e   >   Z E R O _ T I M E )   { 
                 i f   ( ( * t h i s ) . H a s R e m a i n i n g P a t h ( ) )   { 
                         ( * t h i s ) . R u n V e h i c l e ( r u n T i m e ) ; 
                 }   e l s e   { 
                         i s O n V e h i c l e   =   f a l s e ; 
                 } 
         } 
 
         r e s o u r c e . S e t P o s i t i o n ( v e h i c l e . G e t N e x t P o s i t i o n ( ) ) ; 
 } 
 
 
 
 V e h i c l e D r i v e r B e h a v i o r : : ~ V e h i c l e D r i v e r B e h a v i o r ( ) 
 { 
         V e h i c l e &   v e h i c l e   =   * v e h i c l e P t r ; 
         t h e A g e n t G i s P t r - > T a k e O w n e r s h i o p O f V e h i c l e L a s t P o s i t i o n U p d a t e ( r e s o u r c e ,   v e h i c l e P t r ) ; 
 } 
 
 
 v o i d   V e h i c l e D r i v e r B e h a v i o r : : U p d a t e V e l o c i t y ( c o n s t   S i m T i m e &   t i m e S t e p ) 
 { 
         d o u b l e   d i s t a n c e T o S t o p ; 
         d o u b l e   f r o n t V e h i c l e V e l o c i t y ; 
         d o u b l e   m i n D i s t a n c e T o F r o n t V e h i c l e ; 
 
         ( * t h i s ) . V i e w F r o n t S t a t u s ( 
                 d i s t a n c e T o S t o p , 
                 f r o n t V e h i c l e V e l o c i t y , 
                 m i n D i s t a n c e T o F r o n t V e h i c l e ) ; 
 
         c o n s t   d o u b l e   t i m e S t e p S e c   =   d o u b l e ( t i m e S t e p ) / S E C O N D ; 
 
         c o n s t   d o u b l e   a c c e l   = 
                 ( * t h i s ) . C a l c u l a t e I d m B a s e d A c c e l e r a t i o n ( 
                         t i m e S t e p S e c , 
                         d i s t a n c e T o S t o p , 
                         f r o n t V e h i c l e V e l o c i t y ) ; 
 
         v e l o c i t y   =   s t d : : m a x < d o u b l e > ( 0 ,   v e l o c i t y   +   a c c e l * t i m e S t e p S e c ) ; 
 
         v e h i c l e P t r - > S e t N e x t V e l o c i t y ( v e l o c i t y ) ; 
 
         a s s e r t ( v e l o c i t y   > =   0 ) ; 
 } 
 
 v o i d   V e h i c l e D r i v e r B e h a v i o r : : C h a n g e L a n e I f N e c e s s a r y ( ) 
 { 
         i f   ( r o u t e s . e m p t y ( )   | |   p a s s i n g I n t e r s e c t i o n )   { 
                 r e t u r n ; 
         } 
 
         c o n s t   V e h i c l e &   v e h i c l e   =   * v e h i c l e P t r ; 
         c o n s t   V e h i c l e R o u t e &   c u r r e n t R o u t e   =   r o u t e s . f r o n t ( ) ; 
         c o n s t   R o a d &   c u r r e n t R o a d   =   t h e A g e n t G i s P t r - > G e t A g e n t R o a d ( c u r r e n t R o u t e . r o a d I d ) . G e t G i s R o a d ( ) ; 
 
         c o n s t   d o u b l e   p o s s i b l e L a n e C h a n g e A c c e l e r a t i o n   = 
                 C a l c u l a t e I n t e l l i g e n t D r i v e r s M o d e l A c c e l e r a t i o n ( 
                         v e h i c l e , 
                         r e m a i n i n g D i s t a n c e T o I n t e r s e c t i o n   -   v e h i c l e . G e t H a l f B o d y L e n g t h ( ) , 
                         D B L _ M A X , 
                         v e h i c l e . G e t V e h i c l e C o n s t a n t ( ) . m a x V e h i c l e S p e e d ) ; 
 
         i f   ( p o s s i b l e L a n e C h a n g e A c c e l e r a t i o n   <   r e s o u r c e . M a x D e c e l e r a t i o n ( ) )   { 
                 r e t u r n ; 
         } 
 
         i f   ( r o u t e s . s i z e ( )   >   1 )   { 
                 c o n s t   V e h i c l e R o u t e &   n e x t R o u t e   =   r o u t e s [ 1 ] ; 
                 c o n s t   R o a d I d T y p e   n e x t R o a d I d   =   n e x t R o u t e . r o a d I d ; 
 
                 i f   ( ! c u r r e n t R o a d . C a n A p p r o a c h ( c u r r e n t L a n e N u m b e r ,   n e x t R o a d I d )   & & 
                         r e m a i n i n g D i s t a n c e T o I n t e r s e c t i o n   <   f o r c e L a n e C h a n g e D i s t a n c e )   { 
 
                         c o n s t   s i z e _ t   a p p r o a c h L a n e N u m b e r   = 
                                 c u r r e n t R o a d . G e t N e i g h b o r L a n e N u m b e r T o A p p r o a c h ( c u r r e n t L a n e N u m b e r ,   n e x t R o a d I d ) ; 
 
                         ( * t h i s ) . C h a n g e L a n e ( a p p r o a c h L a n e N u m b e r ) ; 
                         r e t u r n ; 
                 } 
         } 
 
         c o n s t   d o u b l e   l a n e C h a n g e R a d i a n s   =   P I   /   1 0 . ; 
         i f   ( c u r r e n t W a y p o i n t R a d i a n s   >   l a n e C h a n g e R a d i a n s   & & 
                 r e m a i n i n g P a t h D i s t a n c e   <   s l o w D o w n D i s t a n c e B e f o r e C u r v e )   { 
                 r e t u r n ; 
         } 
 
         c o n s t   R o a d D i r e c t i o n T y p e   d i r e c t i o n T y p e   =   c u r r e n t R o a d . G e t R o a d D i r e c t i o n ( c u r r e n t L a n e N u m b e r ) ; 
 
         i f   ( c u r r e n t R o a d . H a s P a s s i n g L a n e ( d i r e c t i o n T y p e ,   c u r r e n t L a n e N u m b e r ) )   { 
                 c o n s t   s i z e _ t   r i g h t L a n e N u m b e r   = 
                         c u r r e n t R o a d . G e t P a s s i n g L a n e N u m b e r ( d i r e c t i o n T y p e ,   c u r r e n t L a n e N u m b e r ) ; 
 
                 i f   ( ( * t h i s ) . C a n C h a n g e L a n e ( r i g h t L a n e N u m b e r ) )   { 
                         ( * t h i s ) . C h a n g e L a n e ( r i g h t L a n e N u m b e r ) ; 
                 } 
         } 
 
         i f   ( c u r r e n t R o a d . H a s N o n P a s s i n g L a n e ( d i r e c t i o n T y p e ,   c u r r e n t L a n e N u m b e r ) )   { 
                 c o n s t   s i z e _ t   l e f t L a n e N u m b e r   = 
                         c u r r e n t R o a d . G e t N o n P a s s i n g L a n e N u m b e r ( d i r e c t i o n T y p e ,   c u r r e n t L a n e N u m b e r ) ; 
 
                 i f   ( ( * t h i s ) . C a n C h a n g e L a n e ( l e f t L a n e N u m b e r ) )   { 
                         ( * t h i s ) . C h a n g e L a n e ( l e f t L a n e N u m b e r ) ; 
                 } 
         } 
 } 
 
 b o o l   V e h i c l e D r i v e r B e h a v i o r : : C a n C h a n g e L a n e ( c o n s t   s i z e _ t   n e x t L a n e N u m b e r )   c o n s t 
 { 
         i f   ( l a n e C h a n g e E n a b l e T i m e   >   r e s o u r c e . C u r r e n t T i m e ( )   | |   p a s s i n g I n t e r s e c t i o n )   { 
                 r e t u r n   f a l s e ; 
         } 
 
         a s s e r t ( ! r o u t e s . e m p t y ( ) ) ; 
 
         c o n s t   V e h i c l e &   v e h i c l e   =   * v e h i c l e P t r ; 
         c o n s t   V e h i c l e R o u t e &   c u r r e n t R o u t e   =   r o u t e s . f r o n t ( ) ; 
         c o n s t   A g e n t R o a d &   c u r r e n t R o a d   =   t h e A g e n t G i s P t r - > G e t A g e n t R o a d ( c u r r e n t R o u t e . r o a d I d ) ; 
 
         i f   ( r o u t e s . s i z e ( )   >   1 )   { 
                 c o n s t   V e h i c l e R o u t e &   n e x t R o u t e   =   r o u t e s [ 1 ] ; 
 
                 i f   ( ! c u r r e n t R o a d . G e t G i s R o a d ( ) . C a n A p p r o a c h ( n e x t L a n e N u m b e r ,   n e x t R o u t e . r o a d I d )   & & 
                         r e m a i n i n g D i s t a n c e T o I n t e r s e c t i o n   <   f o r c e L a n e C h a n g e D i s t a n c e )   { 
                         r e t u r n   f a l s e ; 
                 } 
         } 
 
         i f   ( ! ( * t h i s ) . H a s E n o u g h G a p A n d S a f e t y C r i t e r i o n T o C h a n g e L a n e ( n e x t L a n e N u m b e r ) )   { 
                 r e t u r n   f a l s e ; 
         } 
 
         d o u b l e   b a c k V e h i c l e D i s a d v a n t a g e   =   0 ; 
         d o u b l e   p r e v A c c e l ; 
         d o u b l e   n e x t A c c e l ; 
 
         i f   ( c u r r e n t R o a d . H a s F r o n t V e h i c l e ( v e h i c l e ,   c u r r e n t L a n e N u m b e r ) )   { 
                 c o n s t   V e h i c l e &   f r o n t V e h i c l e   = 
                         c u r r e n t R o a d . G e t F r o n t V e h i c l e ( v e h i c l e ,   c u r r e n t L a n e N u m b e r ) ; 
 
                 p r e v A c c e l   =   C a l c u l a t e I n t e l l i g e n t D r i v e r s M o d e l A c c e l e r a t i o n ( v e h i c l e ,   f r o n t V e h i c l e ) ; 
         }   e l s e   { 
                 p r e v A c c e l   =   C a l c u l a t e I n t e l l i g e n t D r i v e r s M o d e l A c c e l e r a t i o n ( v e h i c l e ) ; 
         } 
 
         i f   ( c u r r e n t R o a d . H a s F r o n t V e h i c l e ( v e h i c l e ,   n e x t L a n e N u m b e r ) )   { 
                 c o n s t   V e h i c l e &   f r o n t V e h i c l e   = 
                         c u r r e n t R o a d . G e t F r o n t V e h i c l e ( v e h i c l e ,   n e x t L a n e N u m b e r ) ; 
 
                 i f   ( c u r r e n t R o a d . H a s B a c k V e h i c l e ( v e h i c l e ,   n e x t L a n e N u m b e r ) )   { 
                         c o n s t   V e h i c l e &   b a c k V e h i c l e   = 
                                 c u r r e n t R o a d . G e t B a c k V e h i c l e ( v e h i c l e ,   n e x t L a n e N u m b e r ) ; 
 
                         c o n s t   d o u b l e   n e x t B a c k A c c e l   = 
                                 C a l c u l a t e I n t e l l i g e n t D r i v e r s M o d e l A c c e l e r a t i o n ( b a c k V e h i c l e ,   v e h i c l e ) ; 
 
                         c o n s t   d o u b l e   p r e v B a c k A c c e l   = 
                                 C a l c u l a t e I n t e l l i g e n t D r i v e r s M o d e l A c c e l e r a t i o n ( b a c k V e h i c l e ,   f r o n t V e h i c l e ) ; 
 
                         b a c k V e h i c l e D i s a d v a n t a g e   =   s t d : : m a x ( 0 . ,   n e x t B a c k A c c e l   -   p r e v B a c k A c c e l ) ; 
                 } 
 
                 n e x t A c c e l   =   C a l c u l a t e I n t e l l i g e n t D r i v e r s M o d e l A c c e l e r a t i o n ( v e h i c l e ,   f r o n t V e h i c l e ) ; 
         }   e l s e   { 
                 n e x t A c c e l   =   C a l c u l a t e I n t e l l i g e n t D r i v e r s M o d e l A c c e l e r a t i o n ( v e h i c l e ) ; 
         } 
 
         c o n s t   d o u b l e   o w n A d v a n t a g e   =   n e x t A c c e l   -   p r e v A c c e l ; 
 
         c o n s t   d o u b l e   a c c e l e r a t i o n T h r e s h o l d   = 
                 v e h i c l e . G e t V e h i c l e C o n s t a n t ( ) . l a n e C h a n g e A c c e l e r a t i o n T h r e s h o l d ; 
 
         r e t u r n   ( ( o w n A d v a n t a g e   -   b a c k V e h i c l e D i s a d v a n t a g e )   >   a c c e l e r a t i o n T h r e s h o l d ) ; 
 } 
 
 v o i d   V e h i c l e D r i v e r B e h a v i o r : : C h a n g e L a n e ( c o n s t   s i z e _ t   n e x t L a n e N u m b e r ) 
 { 
         a s s e r t ( ! r o u t e s . e m p t y ( ) ) ; 
 
         V e h i c l e R o u t e &   c u r r e n t R o u t e   =   r o u t e s . f r o n t ( ) ; 
         c o n s t   A g e n t R o a d &   c u r r e n t R o a d   =   t h e A g e n t G i s P t r - > G e t A g e n t R o a d ( c u r r e n t R o u t e . r o a d I d ) ; 
         c o n s t   s i z e _ t   l a s t L a n e N u m b e r   =   c u r r e n t L a n e N u m b e r ; 
 
         i f   ( l a s t L a n e N u m b e r   = =   n e x t L a n e N u m b e r )   { 
                 r e t u r n ; 
         } 
 
         c u r r e n t L a n e N u m b e r   =   n e x t L a n e N u m b e r ; 
 
         v e h i c l e P t r - > S e t N e x t L a n e N u m b e r ( c u r r e n t L a n e N u m b e r ) ; 
         v e h i c l e P t r - > S e t N e x t C h a n g e d L a n e N u m b e r ( l a s t L a n e N u m b e r ) ; 
 
         V e r t e x   n o r m a l V e c t o r ; 
 
         i f   ( c u r r e n t R o a d . G e t G i s R o a d ( ) . G e t R o a d D i r e c t i o n ( n e x t L a n e N u m b e r )   = =   R O A D _ D I R E C T I O N _ U P )   { 
                 i f   ( n e x t L a n e N u m b e r   <   l a s t L a n e N u m b e r )   { 
                         l a n e C h a n g e D i r e c t i o n   =   - 1 ; 
                 }   e l s e   { 
                         l a n e C h a n g e D i r e c t i o n   =   1 ; 
                 } 
         }   e l s e   { 
                 i f   ( n e x t L a n e N u m b e r   >   l a s t L a n e N u m b e r )   { 
                         l a n e C h a n g e D i r e c t i o n   =   - 1 ; 
                 }   e l s e   { 
                         l a n e C h a n g e D i r e c t i o n   =   1 ; 
                 } 
         } 
 
         c o n s t   V e r t e x &   c u r r e n t P o s   =   r e s o u r c e . P o s i t i o n ( ) ; 
 
         d e q u e < V e r t e x > &   c u r r e n t W a y p o i n t s   =   r o u t e s . f r o n t ( ) . r e m a i n i n g W a y p o i n t s ; 
 
         c u r r e n t R o a d . G e t G i s R o a d ( ) . G e t L a n e V e r t i c e s ( 
                 n e x t L a n e N u m b e r ,   t r u e / * w a y p o i n t F r o m A d d i t i o n a l S t a r t P o s i t i o n * / ,   c u r r e n t P o s ,   c u r r e n t W a y p o i n t s ) ; 
 
         a s s e r t ( ! c u r r e n t W a y p o i n t s . e m p t y ( ) ) ; 
         V e r t e x   n e a r e s t P o s i t i o n ; 
         s i z e _ t   v e r t e x N u m b e r ; 
 
         C a l c u l a t e P o i n t T o A r c N e a r e s t P o s i t i o n ( 
                 c u r r e n t W a y p o i n t s , 
                 c u r r e n t P o s , 
                 n e a r e s t P o s i t i o n , 
                 v e r t e x N u m b e r ) ; 
 
         a s s e r t ( v e r t e x N u m b e r   <   c u r r e n t W a y p o i n t s . s i z e ( ) ) ; 
         f o r ( s i z e _ t   i   =   0 ;   i   < =   v e r t e x N u m b e r ;   i + + )   { 
                 c u r r e n t W a y p o i n t s . p o p _ f r o n t ( ) ; 
         } 
         c u r r e n t W a y p o i n t s . p u s h _ f r o n t ( n e a r e s t P o s i t i o n ) ; 
 
         r e m a i n i n g D i s t a n c e T o I n t e r s e c t i o n   = 
                 C a l c u l a t e A r c D i s t a n c e ( c u r r e n t W a y p o i n t s ) ; 
 
         ( * t h i s ) . U p d a t e N e x t R o a d W a y p o i n t I f N e c e s s a r y ( ) ; 
 
         ( * t h i s ) . S e t N e x t W a y p o i n t ( ) ; 
 
         l a n e C h a n g e E n a b l e T i m e   = 
                 r e s o u r c e . C u r r e n t T i m e ( )   +   s t a t i c _ c a s t < S i m T i m e > ( l a n e C h a n g e T i m e S e c ) * S E C O N D ; 
 } 
 
 v o i d   V e h i c l e D r i v e r B e h a v i o r : : U p d a t e N e x t R o a d W a y p o i n t I f N e c e s s a r y ( ) 
 { 
         a s s e r t ( ! r o u t e s . e m p t y ( ) ) ; 
 
         V e h i c l e R o u t e &   c u r r e n t R o u t e   =   r o u t e s . f r o n t ( ) ; 
         c o n s t   R o a d &   c u r r e n t R o a d   =   t h e A g e n t G i s P t r - > G e t A g e n t R o a d ( c u r r e n t R o u t e . r o a d I d ) . G e t G i s R o a d ( ) ; 
 
         i f   ( r o u t e s . s i z e ( )   >   1 )   { 
                 V e h i c l e R o u t e &   n e x t R o u t e   =   r o u t e s [ 1 ] ; 
                 c o n s t   R o a d I d T y p e   n e x t R o a d I d   =   n e x t R o u t e . r o a d I d ; 
 
                 s i z e _ t   a p p r o a c h L a n e N u m b e r   =   c u r r e n t L a n e N u m b e r ; 
 
                 i f   ( ! c u r r e n t R o a d . C a n A p p r o a c h ( c u r r e n t L a n e N u m b e r ,   n e x t R o a d I d ) )   { 
                         a p p r o a c h L a n e N u m b e r   =   c u r r e n t R o a d . G e t A p p r o a c h L a n e N u m b e r ( n e x t R o a d I d ) ; 
                 } 
 
                 c o n s t   R o a d &   n e x t R o a d   =   t h e A g e n t G i s P t r - > G e t A g e n t R o a d ( n e x t R o a d I d ) . G e t G i s R o a d ( ) ; 
 
                 c o n s t   s i z e _ t   n e x t L a n e N u m b e r   = 
                         c u r r e n t R o a d . G e t N e x t L a n e N u m b e r ( a p p r o a c h L a n e N u m b e r ,   n e x t R o a d I d ) ; 
 
                 c o n s t   V e r t e x &   c u r r e n t P o s   =   r e s o u r c e . P o s i t i o n ( ) ; 
 
                 V e r t e x   s t a r t P o s i t i o n ; 
 
                 i f   ( r o u t e s [ 0 ] . r e m a i n i n g W a y p o i n t s . e m p t y ( ) )   { 
                         s t a r t P o s i t i o n   =   c u r r e n t P o s ; 
                 } 
                 e l s e   { 
                         s t a r t P o s i t i o n   =   r o u t e s [ 0 ] . r e m a i n i n g W a y p o i n t s . b a c k ( ) ; 
                 } 
 
                 n e x t R o a d . G e t L a n e V e r t i c e s ( 
                         n e x t L a n e N u m b e r , 
                         t r u e / * w a y p o i n t F r o m A d d i t i o n a l S t a r t P o s i t i o n * / , 
                         s t a r t P o s i t i o n , 
                         n e x t R o u t e . r e m a i n i n g W a y p o i n t s ) ; 
 
 
                 i f   ( n e x t R o a d . I s E x t r a P a t h ( ) )   { 
                         / /   d i s c a r d   i n t e r s e c t i o n   v e r t e x 
                         i f   ( n e x t R o u t e . r e m a i n i n g W a y p o i n t s . s i z e ( )   >   1 )   { 
                                 n e x t R o u t e . r e m a i n i n g W a y p o i n t s . p o p _ f r o n t ( ) ; 
                         } 
                 } 
 
                 a s s e r t ( ! n e x t R o u t e . r e m a i n i n g W a y p o i n t s . e m p t y ( ) ) ; 
         } 
 } 
 
 b o o l   V e h i c l e D r i v e r B e h a v i o r : : H a s E n o u g h G a p A n d S a f e t y C r i t e r i o n T o C h a n g e L a n e ( 
         c o n s t   s i z e _ t   l a n e N u m b e r )   c o n s t 
 { 
         c o n s t   V e h i c l e R o u t e &   c u r r e n t R o u t e   =   r o u t e s . f r o n t ( ) ; 
         c o n s t   A g e n t R o a d &   c u r r e n t R o a d   =   t h e A g e n t G i s P t r - > G e t A g e n t R o a d ( c u r r e n t R o u t e . r o a d I d ) ; 
 
         c o n s t   V e h i c l e &   v e h i c l e   =   * v e h i c l e P t r ; 
 
         i f   ( c u r r e n t R o a d . H a s F r o n t V e h i c l e ( v e h i c l e ,   l a n e N u m b e r ) )   { 
                 c o n s t   V e h i c l e &   f r o n t V e h i c l e   =   c u r r e n t R o a d . G e t F r o n t V e h i c l e ( v e h i c l e ,   l a n e N u m b e r ) ; 
                 c o n s t   V e h i c l e C o n s t a n t &   v e h i c l e C o n s t a n t   =   v e h i c l e . G e t V e h i c l e C o n s t a n t ( ) ; 
 
                 c o n s t   d o u b l e   d i s t a n c e T o F r o n t   = 
                         r e m a i n i n g D i s t a n c e T o I n t e r s e c t i o n   -   f r o n t V e h i c l e . G e t D i s t a n c e T o I n t e r s e c t i o n ( )   - 
                         ( f r o n t V e h i c l e . G e t H a l f B o d y L e n g t h ( )   +   v e h i c l e . G e t H a l f B o d y L e n g t h ( ) ) ; 
 
                 i f   ( d i s t a n c e T o F r o n t   < =   v e h i c l e C o n s t a n t . m i n V e h i c l e G a p )   { 
                         r e t u r n   f a l s e ; 
                 } 
 
                 c o n s t   d o u b l e   b i a s S a v e   =   v e h i c l e C o n s t a n t . s a v e A c c e l e r a t i o n ; 
 
                 i f   ( C a l c u l a t e I n t e l l i g e n t D r i v e r s M o d e l A c c e l e r a t i o n ( v e h i c l e ,   f r o n t V e h i c l e )   <   b i a s S a v e )   { 
                         r e t u r n   f a l s e ; 
                 } 
         } 
 
         i f   ( c u r r e n t R o a d . H a s B a c k V e h i c l e ( v e h i c l e ,   l a n e N u m b e r ) )   { 
                 c o n s t   V e h i c l e &   b a c k V e h i c l e   =   c u r r e n t R o a d . G e t B a c k V e h i c l e ( v e h i c l e ,   l a n e N u m b e r ) ; 
                 c o n s t   V e h i c l e C o n s t a n t &   v e h i c l e C o n s t a n t   =   b a c k V e h i c l e . G e t V e h i c l e C o n s t a n t ( ) ; 
 
                 c o n s t   d o u b l e   d i s t a n c e T o F r o n t   = 
                         b a c k V e h i c l e . G e t D i s t a n c e T o I n t e r s e c t i o n ( )   -   r e m a i n i n g D i s t a n c e T o I n t e r s e c t i o n   - 
                         ( v e h i c l e . G e t H a l f B o d y L e n g t h ( )   +   b a c k V e h i c l e . G e t H a l f B o d y L e n g t h ( ) ) ; 
 
                 i f   ( d i s t a n c e T o F r o n t   < =   v e h i c l e C o n s t a n t . m i n V e h i c l e G a p )   { 
                         r e t u r n   f a l s e ; 
                 } 
 
                 c o n s t   d o u b l e   b i a s S a v e S e l f   =   v e h i c l e C o n s t a n t . s a v e A c c e l e r a t i o n ; 
 
                 i f   ( C a l c u l a t e I n t e l l i g e n t D r i v e r s M o d e l A c c e l e r a t i o n ( b a c k V e h i c l e ,   v e h i c l e )   <   b i a s S a v e S e l f )   { 
                         r e t u r n   f a l s e ; 
                 } 
         } 
 
         r e t u r n   t r u e ; 
 } 
 
 d o u b l e   V e h i c l e D r i v e r B e h a v i o r : : G e t R e m a i n i n g L a n e c h a n g e R a t e ( )   c o n s t 
 { 
         c o n s t   d o u b l e   r e m a i n i n g T i m e   = 
                 s t a t i c _ c a s t < d o u b l e > ( l a n e C h a n g e E n a b l e T i m e   -   r e s o u r c e . C u r r e n t T i m e ( ) )   /   S E C O N D ; 
 
         a s s e r t ( r e m a i n i n g T i m e   > =   0 ) ; 
 
         r e t u r n   r e m a i n i n g T i m e   /   l a n e C h a n g e T i m e S e c ; 
 } 
 
 d o u b l e   V e h i c l e D r i v e r B e h a v i o r : : C a l c u l a t e I n t e l l i g e n t D r i v e r s M o d e l A c c e l e r a t i o n ( 
         c o n s t   V e h i c l e &   v e h i c l e , 
         c o n s t   d o u b l e   d i s t a n c e T o F r o n t P o i n t , 
         c o n s t   d o u b l e   f r o n t O b s t r u c t i o n V e l o c i t y , 
         c o n s t   d o u b l e   m a x V e l o c i t y ) 
 { 
         c o n s t   d o u b l e   o r i g i n a l V e l o c i t y   =   v e h i c l e . G e t V e l o c i t y M e t e r s P e r S e c ( ) ; 
         c o n s t   V e h i c l e C o n s t a n t &   v e h i c l e C o n s t a n t   =   v e h i c l e . G e t V e h i c l e C o n s t a n t ( ) ; 
 
         c o n s t   d o u b l e   m a x A c c e l   =   v e h i c l e C o n s t a n t . m a x A c c e l e r a t i o n ; 
         c o n s t   d o u b l e   m a x D e c e l   =   f a b s ( v e h i c l e C o n s t a n t . m a x D e c e l a r a t i o n ) ; 
 
         c o n s t   d o u b l e   d v   =   o r i g i n a l V e l o c i t y   -   f r o n t O b s t r u c t i o n V e l o c i t y ; 
         c o n s t   d o u b l e   s   =   d i s t a n c e T o F r o n t P o i n t ; / / a c t u a l   g a p 
         c o n s t   d o u b l e   s 0   =   v e h i c l e C o n s t a n t . m i n V e h i c l e G a p ; 
         c o n s t   d o u b l e   s 1   =   v e h i c l e C o n s t a n t . v e l o c i t y R a t i o G a p D i s t a n c e ;   / / 0 m   < =   s 1   < =   1 5 m 
         c o n s t   d o u b l e   v e l o c i t y R a t i o   =   o r i g i n a l V e l o c i t y / m a x V e l o c i t y ; 
         c o n s t   d o u b l e   T   =   v e h i c l e C o n s t a n t . t i m e H e a d w a y ; 
 
         c o n s t   d o u b l e   s s t a r   = 
                 s 0   +   s t d : : m a x ( 0 . ,   ( s 1 * s q r t ( v e l o c i t y R a t i o )   +   o r i g i n a l V e l o c i t y * T   +   ( o r i g i n a l V e l o c i t y * d v ) / ( 2 * s q r t ( f a b s ( m a x A c c e l * m a x D e c e l ) ) ) ) ) ; / / d e s i r e d   m i n i m u m   g a p 
 
         c o n s t   d o u b l e   a c c e l e r a t i o n E x p o n e n t   =   v e h i c l e C o n s t a n t . a c c e l e r a t i o n E x p o n e n t ; 
         c o n s t   d o u b l e   a c c e l   =   m a x A c c e l   *   ( 1   -   p o w ( v e l o c i t y R a t i o ,   a c c e l e r a t i o n E x p o n e n t )   -   ( s s t a r * s s t a r ) / ( s * s ) ) ; 
 
         d o u b l e   m a x B r a k i n g D e c e l   =   v e h i c l e C o n s t a n t . m a x B r a k i n g D e c c e l e r a t i o n ; 
 
         i f   ( o r i g i n a l V e l o c i t y   < =   0 )   { 
                 m a x B r a k i n g D e c e l   =   0 . ; 
         } 
 
         r e t u r n   s t d : : m a x ( a c c e l ,   m a x B r a k i n g D e c e l ) ; 
 } 
 
 d o u b l e   V e h i c l e D r i v e r B e h a v i o r : : C a l c u l a t e I n t e l l i g e n t D r i v e r s M o d e l A c c e l e r a t i o n ( 
         c o n s t   V e h i c l e &   v e h i c l e , 
         c o n s t   V e h i c l e &   f r o n t V e h i c l e ) 
 { 
         c o n s t   d o u b l e   d i s t a n c e T o F r o n t   = 
                 v e h i c l e . G e t D i s t a n c e T o I n t e r s e c t i o n ( )   -   f r o n t V e h i c l e . G e t D i s t a n c e T o I n t e r s e c t i o n ( )   - 
                 ( f r o n t V e h i c l e . G e t H a l f B o d y L e n g t h ( )   +   v e h i c l e . G e t H a l f B o d y L e n g t h ( ) ) ; 
 
         r e t u r n   C a l c u l a t e I n t e l l i g e n t D r i v e r s M o d e l A c c e l e r a t i o n ( 
                 v e h i c l e , 
                 d i s t a n c e T o F r o n t , 
                 f r o n t V e h i c l e . G e t V e l o c i t y M e t e r s P e r S e c ( ) , 
                 v e h i c l e . G e t V e h i c l e C o n s t a n t ( ) . m a x V e h i c l e S p e e d ) ; 
 } 
 
 d o u b l e   V e h i c l e D r i v e r B e h a v i o r : : C a l c u l a t e I n t e l l i g e n t D r i v e r s M o d e l A c c e l e r a t i o n ( 
         c o n s t   V e h i c l e &   v e h i c l e ) 
 { 
         r e t u r n   C a l c u l a t e I n t e l l i g e n t D r i v e r s M o d e l A c c e l e r a t i o n ( 
                 v e h i c l e , 
                 D B L _ M A X , 
                 D B L _ M A X , 
                 v e h i c l e . G e t V e h i c l e C o n s t a n t ( ) . m a x V e h i c l e S p e e d ) ; 
 } 
 
 d o u b l e   V e h i c l e D r i v e r B e h a v i o r : : C a l c u l a t e F r e e R u n A c c e l e r a t i o n ( 
         c o n s t   d o u b l e   o r i g i n a l V e l o c i t y , 
         c o n s t   d o u b l e   m a x V e l o c i t y ) 
 { 
         c o n s t   d o u b l e   t a 0   =   2 . 4 5 ;   / /   [ s ] 
 
         r e t u r n   ( m a x V e l o c i t y   -   o r i g i n a l V e l o c i t y ) / t a 0 ; 
 } 
 
 d o u b l e   V e h i c l e D r i v e r B e h a v i o r : : C a l c u l a t e D e s i r e d V e l o c i t y ( 
         c o n s t   A g e n t R o a d &   p a s s i n g R o a d , 
         c o n s t   V e h i c l e &   v e h i c l e , 
         c o n s t   d o u b l e   d i s t a n c e T o V e r t e x , 
         c o n s t   d o u b l e   r a d i a n s T o N e x t P o i n t ) 
 { 
         c o n s t   V e h i c l e C o n s t a n t &   v e h i c l e C o n s t a n t   =   v e h i c l e . G e t V e h i c l e C o n s t a n t ( ) ; 
 
         c o n s t   d o u b l e   m a x V e l o c i t y   = 
                 s t d : : m i n ( p a s s i n g R o a d . G e t G i s R o a d ( ) . G e t S p e e d L i m i t M e t e r s P e r S e c ( ) , 
                                   v e h i c l e C o n s t a n t . m a x V e h i c l e S p e e d ) ; 
 
         i f   ( m a x V e l o c i t y   < =   0 . )   { 
                 c e r r   < <   " E r r o r :   M a x i m u m   v e l o c i t y   i s   "   < <   m a x V e l o c i t y   < <   e n d l 
                           < <   "     V e h i c l e   v e l o c i t y   m u s t   b e   g r e a t e r   t h a n   0 . "   < <   e n d l ; 
                 e x i t ( 1 ) ; 
         } 
 
         i f   ( d i s t a n c e T o V e r t e x   >   s l o w D o w n D i s t a n c e B e f o r e C u r v e )   { 
                 r e t u r n   m a x V e l o c i t y ; 
         } 
 
         c o n s t   d o u b l e   m i n V e l o c i t y   =   v e h i c l e C o n s t a n t . m a x T u r n S p e e d ; 
 
         i f   ( m i n V e l o c i t y   < =   0 . )   { 
                 c e r r   < <   " E r r o r :   M i n i m u m   v e l o c i t y   i s   "   < <   m i n V e l o c i t y   < <   e n d l 
                           < <   "     V e h i c l e   v e l o c i t y   m u s t   b e   g r e a t e r   t h a n   0 . "   < <   e n d l ; 
                 e x i t ( 1 ) ; 
         } 
 
         i f   ( m a x V e l o c i t y   <   m i n V e l o c i t y )   { 
                 r e t u r n   m a x V e l o c i t y ; 
         } 
 
         a s s e r t ( r a d i a n s T o N e x t P o i n t   > =   0 ) ; 
         a s s e r t ( r a d i a n s T o N e x t P o i n t   < =   P I ) ; 
 
         / /   N o t e :   l i n e a r   v e l o c i t y   l i m i t a t i o n   c a l c u l a t i o n . 
         / /               m a y b e   e x p o n e n t   c a l c u l a t i o n   i s   b e t t e r . 
 
         c o n s t   d o u b l e   r e q u i r e d V e l o c i t y   = 
                 ( m a x V e l o c i t y - m i n V e l o c i t y ) * ( ( r a d i a n s T o N e x t P o i n t ) / P I )   +   m i n V e l o c i t y ; 
 
         r e t u r n   r e q u i r e d V e l o c i t y ; 
 } 
 
 d o u b l e   V e h i c l e D r i v e r B e h a v i o r : : C a l c u l a t e I d m B a s e d A c c e l e r a t i o n ( 
         c o n s t   d o u b l e   t i m e S t e p S e c , 
         c o n s t   d o u b l e   d i s t a n c e T o S t o p , 
         c o n s t   d o u b l e   f r o n t V e h i c l e V e l o c i t y )   c o n s t 
 { 
         a s s e r t ( ! r o u t e s . e m p t y ( ) ) ; 
         c o n s t   V e h i c l e R o u t e &   c u r r e n t R o u t e   =   r o u t e s . f r o n t ( ) ; 
 
         c o n s t   d o u b l e   m a x V e l o c i t y   = 
                 C a l c u l a t e D e s i r e d V e l o c i t y ( 
                         t h e A g e n t G i s P t r - > G e t A g e n t R o a d ( c u r r e n t R o u t e . r o a d I d ) , 
                         * v e h i c l e P t r , 
                         r e m a i n i n g P a t h D i s t a n c e , 
                         c u r r e n t W a y p o i n t R a d i a n s ) ; 
 
         i f   ( m a x V e l o c i t y   < =   0 )   { 
                 c e r r   < <   " E r r o r :   M a x   v e h i c l e   s p e e d   i s   0 .   S e t   V e h i c l e S p e e d   i n   A g e n t P r o f i l e . "   < <   e n d l ; 
                 e x i t ( 1 ) ; 
         } 
 
         r e t u r n   C a l c u l a t e I n t e l l i g e n t D r i v e r s M o d e l A c c e l e r a t i o n ( 
                 * v e h i c l e P t r , 
                 d i s t a n c e T o S t o p , 
                 f r o n t V e h i c l e V e l o c i t y , 
                 m a x V e l o c i t y ) ; 
 } 
 
 v o i d   V e h i c l e D r i v e r B e h a v i o r : : R u n V e h i c l e ( c o n s t   S i m T i m e &   r u n D u r a t i o n ) 
 { 
         ( * t h i s ) . U p d a t e V e l o c i t y ( r u n D u r a t i o n ) ; 
 
         ( * t h i s ) . C h a n g e L a n e I f N e c e s s a r y ( ) ; 
 
         i f   ( v e l o c i t y   = =   0 )   { 
                 r e t u r n ; 
         } 
 
         d o u b l e   r e m a i n i n g T i m e S e c   =   d o u b l e ( r u n D u r a t i o n ) / S E C O N D ; 
 
         w h i l e   ( ( * t h i s ) . H a s R e m a i n i n g P a t h ( )   & &   r e m a i n i n g T i m e S e c   >   0 )   { 
 
                 c o n s t   d o u b l e   r u n D i s t a n c e   =   v e l o c i t y * r e m a i n i n g T i m e S e c ; 
 
                 v e h i c l e P t r - > r u n n i n g D i s t a n c e   + =   r u n D i s t a n c e ; 
 
                 i f   ( r e m a i n i n g P a t h D i s t a n c e   < =   r u n D i s t a n c e   +   e n o u g h M i n D i s t a n c e )   { 
                         r e m a i n i n g T i m e S e c   =   s t d : : m a x ( 0 . , r e m a i n i n g T i m e S e c   -   f a b s ( r e m a i n i n g P a t h D i s t a n c e   /   v e l o c i t y ) ) ; 
 
                         r e m a i n i n g D i s t a n c e T o I n t e r s e c t i o n   - =   r e m a i n i n g P a t h D i s t a n c e ; 
 
                         ( * t h i s ) . U p d a t e V i s i b l e R o u t e I f N e c e s s a r y ( ) ; 
                         ( * t h i s ) . S e t N e x t W a y p o i n t ( ) ; 
 
                         i f   ( r e m a i n i n g S h o r t S t o p T i m e   >   Z E R O _ T I M E )   { 
                                 r e m a i n i n g S h o r t S t o p T i m e   = 
                                         s t d : : m a x ( m i n S h o r t S t o p T i m e , 
                                                           r e m a i n i n g S h o r t S t o p T i m e   -   s t a t i c _ c a s t < S i m T i m e > ( r e m a i n i n g T i m e S e c * S E C O N D ) ) ; 
                                 b r e a k ; 
                         } 
 
                 }   e l s e   { 
                         r e m a i n i n g T i m e S e c   =   0 ; 
 
                         r e m a i n i n g D i s t a n c e T o I n t e r s e c t i o n   - =   r u n D i s t a n c e ; 
 
                         r e m a i n i n g P a t h D i s t a n c e   - =   r u n D i s t a n c e ; 
 
                         ( * t h i s ) . U p d a t e V i s i b l e R o u t e I f N e c e s s a r y ( ) ; 
                 } 
         } 
 
         i f   ( ! r o u t e s . e m p t y ( ) )   { 
                 c o n s t   V e h i c l e R o u t e &   c u r r e n t R o u t e   =   r o u t e s . f r o n t ( ) ; 
                 c o n s t   V e r t e x &   n e x t P o s   =   c u r r e n t R o u t e . r e m a i n i n g W a y p o i n t s . f r o n t ( ) ; 
 
                 V e h i c l e &   v e h i c l e   =   * v e h i c l e P t r ; 
 
                 V e r t e x   p o s i t i o n   =   C a l c u l a t e N e x t V e r t e x ( n e x t P o s ,   d i r e c t i o n V e c t o r ,   r e m a i n i n g P a t h D i s t a n c e ) ; 
 
                 i f   ( ( * t h i s ) . I s C h a n g i n g L a n e ( ) )   { 
                         c o n s t   V e r t e x   n o r m a l V e c t o r   = 
                                 d i r e c t i o n V e c t o r . X Y P o i n t ( ) . N o r m a l V e c t o r ( ) . N o r m a l i z e d ( ) * l a n e C h a n g e D i r e c t i o n ; 
 
                         c o n s t   A g e n t R o a d &   c u r r e n t R o a d   =   t h e A g e n t G i s P t r - > G e t A g e n t R o a d ( c u r r e n t R o u t e . r o a d I d ) ; 
 
                         c o n s t   d o u b l e   l a n e W i d t h   =   c u r r e n t R o a d . G e t G i s R o a d ( ) . G e t L a n e W i d t h M e t e r s ( ) ; 
 
                         c o n s t   d o u b l e   r e m a i n i n g L a n e C h a n g e R a t e   =   ( * t h i s ) . G e t R e m a i n i n g L a n e c h a n g e R a t e ( ) ; 
 
                         p o s i t i o n   + =   n o r m a l V e c t o r * l a n e W i d t h * r e m a i n i n g L a n e C h a n g e R a t e ; 
                 }   e l s e   { 
                         v e h i c l e . S e t N e x t C h a n g e d L a n e N u m b e r ( V e h i c l e : : N O _ C H A N G E D _ L A N E _ N U M B E R ) ; 
                 } 
 
                 v e h i c l e . S e t N e x t P o s i t i o n ( p o s i t i o n ) ; 
                 v e h i c l e . S e t N e x t D i s t a n c e T o I n t e r s e c t i o n ( r e m a i n i n g D i s t a n c e T o I n t e r s e c t i o n ) ; 
         } 
 } 
 
 
 
 v o i d   V e h i c l e D r i v e r B e h a v i o r : : A s s i g n F i r s t R o u t e ( ) 
 { 
         V e h i c l e &   v e h i c l e   =   * v e h i c l e P t r ; 
 
         v i e w d R o u t e N u m b e r   =   0 ; 
         v e h i c l e . v i a p o i n t V e r t e x I d   =   r e s o u r c e . L a s t V e r t e x I d ( ) ; 
 
         i f   ( r o u t e P t r - > r o a d R o u t e s . e m p t y ( ) )   { 
                 r e t u r n ; 
         } 
 
         c o n s t   R o a d R o u t e &   r o a d R o u t e   =   r o u t e P t r - > G e t R o a d R o u t e ( v i e w d R o u t e N u m b e r ) ; 
         c o n s t   R o a d &   r o a d   =   t h e A g e n t G i s P t r - > G e t A g e n t R o a d ( r o a d R o u t e . r o a d I d ) . G e t G i s R o a d ( ) ; 
         c o n s t   V e r t e x &   c u r r e n t P o s   =   r e s o u r c e . P o s i t i o n ( ) ; 
 
         c u r r e n t L a n e N u m b e r   = 
                 r o a d . G e t N e a r e s t O u t g o i n g L a n e N u m b e r ( r e s o u r c e . L a s t V e r t e x I d ( ) ,   r e s o u r c e . P o s i t i o n ( ) ) ; 
 
         r o u t e s . c l e a r ( ) ; 
         r o u t e s . p u s h _ b a c k ( V e h i c l e R o u t e ( ) ) ; 
         V e h i c l e R o u t e &   r o u t e   =   r o u t e s . b a c k ( ) ; 
 
         r o u t e . r o a d I d   =   r o a d R o u t e . r o a d I d ; 
         r o u t e . o u t g o i n g V e r t e x I d   =   r o a d R o u t e . n e x t V e r t e x I d ; 
         r o a d . G e t L a n e V e r t i c e s ( c u r r e n t L a n e N u m b e r ,   t r u e / * w a y p o i n t F r o m A d d i t i o n a l S t a r t P o s i t i o n * / ,   c u r r e n t P o s ,   r o u t e . r e m a i n i n g W a y p o i n t s ) ; 
 
         a s s e r t ( r o u t e . r e m a i n i n g W a y p o i n t s . s i z e ( )   >   1 ) ; 
 
         / /   A d j u s t   B u s   A g e n t   d i r e c t i o n . 
 
         i f   ( ( * t h i s ) . G e t B e h a v i o r T y p e ( )   ! =   A G E N T _ B E H A V I O R _ B U S _ D R I V E R )   { 
                 i f   ( r o u t e . r e m a i n i n g W a y p o i n t s . f r o n t ( )   ! =   r e s o u r c e . P o s i t i o n ( ) )   { 
                         r o u t e . r e m a i n i n g W a y p o i n t s . p u s h _ f r o n t ( r e s o u r c e . P o s i t i o n ( ) ) ; 
                 } 
         } 
 
         r e m a i n i n g D i s t a n c e T o I n t e r s e c t i o n   =   C a l c u l a t e A r c D i s t a n c e ( r o u t e . r e m a i n i n g W a y p o i n t s ) ; 
 
         a s s e r t ( ! r o a d . I s B u i l d i n g P a r k i n g R o a d ( ) ) ; 
 
         c o n s t   R o a d &   c u r r e n t V e h i c l e R o a d   =   t h e A g e n t G i s P t r - > G e t A g e n t R o a d ( v e h i c l e . G e t R o a d I d ( ) ) . G e t G i s R o a d ( ) ; 
 
         i f   ( ( G e t B e h a v i o r T y p e ( )   = =   A G E N T _ B E H A V I O R _ V E H I C L E )   & & 
                 ( c u r r e n t V e h i c l e R o a d . I s B u i l d i n g P a r k i n g R o a d ( ) ) )   { 
 
                 c o n s t   B u i l d i n g I d T y p e   b u i l d i n g I d   =   c u r r e n t V e h i c l e R o a d . G e t B u i l d i n g I d ( ) ; 
 
                 t h e A g e n t G i s P t r - > L e a v e F r o m P a r k i n g ( r e s o u r c e ,   b u i l d i n g I d ) ; 
 
         } / / i f / / 
 
         a s s e r t ( ! r o u t e s . f r o n t ( ) . r e m a i n i n g W a y p o i n t s . e m p t y ( ) ) ; 
         v e h i c l e . S e t N e x t V e l o c i t y ( v e l o c i t y ) ; 
         v e h i c l e . S e t N e x t D i s t a n c e T o I n t e r s e c t i o n ( r e m a i n i n g D i s t a n c e T o I n t e r s e c t i o n ) ; 
         v e h i c l e . S e t N e x t L a n e N u m b e r ( c u r r e n t L a n e N u m b e r ) ; 
         v e h i c l e . S e t N e x t R o a d I d ( r o u t e . r o a d I d ) ; 
 
         r e s o u r c e . S e t D e s i r e d N e x t P o s i t i o n I d ( G I S _ R O A D ,   r o u t e . r o a d I d ) ; 
 
         v i e w d R o u t e N u m b e r + + ; 
 
         ( * t h i s ) . U p d a t e V i s i b l e R o u t e I f N e c e s s a r y ( ) ; 
 
         ( * t h i s ) . S e t N e x t W a y p o i n t ( ) ; 
 } 
 
 v o i d   V e h i c l e D r i v e r B e h a v i o r : : R i d e O n V e h i c l e ( ) 
 { 
         p e d e s t r i a n P t r . r e s e t ( ) ; 
 
         i s O n V e h i c l e   =   t r u e ; 
 
         v e h i c l e P t r - > r u n n i n g D i s t a n c e   =   0 ; 
 
         ( * t h i s ) . A s s i g n F i r s t R o u t e ( ) ; 
 } 
 
 v o i d   V e h i c l e D r i v e r B e h a v i o r : : V i e w F r o n t S t a t u s ( 
         d o u b l e &   d i s t a n c e T o S t o p , 
         d o u b l e &   f r o n t V e h i c l e V e l o c i t y , 
         d o u b l e &   m i n D i s t a n c e T o F r o n t V e h i c l e ) 
 { 
         c o n s t   V e h i c l e &   v e h i c l e   =   * v e h i c l e P t r ; 
 
         a s s e r t ( ! r o u t e s . e m p t y ( ) ) ; 
         c o n s t   V e h i c l e R o u t e &   c u r r e n t R o u t e   =   r o u t e s . f r o n t ( ) ; 
         c o n s t   A g e n t R o a d &   c u r r e n t R o a d   =   t h e A g e n t G i s P t r - > G e t A g e n t R o a d ( c u r r e n t R o u t e . r o a d I d ) ; 
 
         d i s t a n c e T o S t o p   =   D B L _ M A X ; 
         f r o n t V e h i c l e V e l o c i t y   =   D B L _ M A X ; 
         m i n D i s t a n c e T o F r o n t V e h i c l e   =   1 . 3 8 ;   / /   [ m ] 
 
         i f   ( c u r r e n t R o a d . H a s F r o n t V e h i c l e ( * v e h i c l e P t r ,   c u r r e n t L a n e N u m b e r ) )   { 
                 c o n s t   V e h i c l e &   f r o n t V e h i c l e   = 
                         c u r r e n t R o a d . G e t F r o n t V e h i c l e ( * v e h i c l e P t r ,   c u r r e n t L a n e N u m b e r ) ; 
 
                 / / a s s e r t ( f r o n t V e h i c l e . G e t D i s t a n c e T o I n t e r s e c t i o n ( )   < =   r e m a i n i n g D i s t a n c e T o I n t e r s e c t i o n ) ; 
 
                 i f   ( f r o n t V e h i c l e . G e t D i s t a n c e T o I n t e r s e c t i o n ( )   <   r e m a i n i n g D i s t a n c e T o I n t e r s e c t i o n )   { 
 
                         c o n s t   d o u b l e   d i s t a n c e T o F r o n t   = 
                                 r e m a i n i n g D i s t a n c e T o I n t e r s e c t i o n   -   f r o n t V e h i c l e . G e t D i s t a n c e T o I n t e r s e c t i o n ( ) ; 
 
                         d i s t a n c e T o S t o p   =   s t d : : m i n ( 
                                 d i s t a n c e T o S t o p , 
                                 s t d : : m a x ( 
                                         0 . ,   d i s t a n c e T o F r o n t   -   ( f r o n t V e h i c l e . G e t H a l f B o d y L e n g t h ( )   +   v e h i c l e . G e t H a l f B o d y L e n g t h ( ) ) ) ) ;   / /   f o r   i n t e r m e d i a t e   d e s t 
                         f r o n t V e h i c l e V e l o c i t y   =   f r o n t V e h i c l e . G e t V e l o c i t y M e t e r s P e r S e c ( ) ; 
 
                 }   e l s e   { 
                         d i s t a n c e T o S t o p   =   0 ; 
                         f r o n t V e h i c l e V e l o c i t y   =   0 ; 
                 } 
                 r e t u r n ; 
         } 
 
         c o n s t   d o u b l e   r e m a i n i n g D i s t a n c e T o S t o p   =   r e m a i n i n g D i s t a n c e T o I n t e r s e c t i o n ; 
 
         c o n s t   d o u b l e   n e a r S t o p D i s t a n c e   =   1 0 0 ; 
         i f   ( r e m a i n i n g D i s t a n c e T o S t o p   >   n e a r S t o p D i s t a n c e )   { 
                 r e t u r n ; 
         } 
 
         / /   n e x t   i n t e r s e c t i o n   i s   e n d   v e r t e x 
         i f   ( r o u t e s . e m p t y ( ) )   { 
                 f r o n t V e h i c l e V e l o c i t y   =   0 ; 
                 m i n D i s t a n c e T o F r o n t V e h i c l e   =   0 ; 
                 r e t u r n ; 
         } 
 
         d i s t a n c e T o S t o p   =   s t d : : m a x ( 0 . ,   r e m a i n i n g D i s t a n c e T o I n t e r s e c t i o n   -   v e h i c l e . G e t H a l f B o d y L e n g t h ( ) ) ; 
 
         c o n s t   G i s S u b s y s t e m &   s u b s y s t e m   =   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) ; 
         c o n s t   i n t   n u m b e r V i s i b l e T u r n s   =   3 ; 
         c o n s t   S i m T i m e   c u r r e n t T i m e   =   r e s o u r c e . C u r r e n t T i m e ( ) ; 
 
         i n t   n u m b e r V e h i c l e R o u t e T u r n s   =   0 ; 
         b o o l   f o u n d S t o p P o i n t   =   f a l s e ; 
 
         s i z e _ t   l a s t L a n e N u m b e r   =   c u r r e n t L a n e N u m b e r ; 
 
         f o r ( s i z e _ t   i   =   0 ; 
                 ( ( i   <   r o u t e s . s i z e ( )   -   1 )   & & 
                   ( n u m b e r V e h i c l e R o u t e T u r n s   <   n u m b e r V i s i b l e T u r n s )   & & 
                   ( ! f o u n d S t o p P o i n t ) ) ;   i + + )   { 
 
                 c o n s t   V e h i c l e R o u t e &   r o u t e 1   =   r o u t e s [ i ] ; 
                 V e h i c l e R o u t e &   r o u t e 2   =   r o u t e s [ i + 1 ] ; 
 
                 c o n s t   I n t e r s e c t i o n I d T y p e   i n t e r s e c t i o n I d   = 
                         s u b s y s t e m . G e t I n t e r s e c t i o n I d ( r o u t e 1 . o u t g o i n g V e r t e x I d ) ; 
 
                 c o n s t   A g e n t I n t e r s e c t i o n &   i n t e r s e c t i o n   = 
                         t h e A g e n t G i s P t r - > G e t A g e n t I n t e r s e c t i o n ( i n t e r s e c t i o n I d ) ; 
 
                 c o n s t   A g e n t R o a d &   l a s t R o a d   = 
                         t h e A g e n t G i s P t r - > G e t A g e n t R o a d ( r o u t e 1 . r o a d I d ) ; 
 
                 c o n s t   A g e n t R o a d &   n e x t R o a d   = 
                         t h e A g e n t G i s P t r - > G e t A g e n t R o a d ( r o u t e 2 . r o a d I d ) ; 
 
                 i f   ( c u r r e n t T i m e   <   r o u t e 2 . e n t r a n c e E n a b l e d T i m e )   { 
                         f r o n t V e h i c l e V e l o c i t y   =   0 ; 
                         m i n D i s t a n c e T o F r o n t V e h i c l e   =   0 ; 
                         f o u n d S t o p P o i n t   =   t r u e ; 
                         b r e a k ; 
                 } 
 
                 c o n s t   b o o l   i s A p p r o a c h L a n e   = 
                         l a s t R o a d . G e t G i s R o a d ( ) . C a n A p p r o a c h ( l a s t L a n e N u m b e r ,   r o u t e 2 . r o a d I d ) ; 
 
                 i f   ( ! i s A p p r o a c h L a n e )   { 
                         f o u n d S t o p P o i n t   =   t r u e ; 
                         b r e a k ; 
                 } 
 
                 b o o l   s e e i n g A P e d e s t r i a n   =   f a l s e ; 
 
                 i f   ( l a s t R o a d . C r o s s i n g A P e d e s t r i a n ( r o u t e 1 . o u t g o i n g V e r t e x I d )   | | 
                         n e x t R o a d . C r o s s i n g A P e d e s t r i a n ( r o u t e 1 . o u t g o i n g V e r t e x I d ) )   { 
 
                         H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d o m N u m b e r G e n e r a t o r   =   r e s o u r c e . G e t R a n d o m N u m b e r G e n e r a t o r ( ) ; 
 
                         s e e i n g A P e d e s t r i a n   = 
                                 ( r a n d o m N u m b e r G e n e r a t o r . G e n e r a t e R a n d o m D o u b l e ( )   <   r e s o u r c e . S e e i n g P e d e s t r i a n P r o b a b i l i t y ( ) ) ; 
                 } 
 
                 c o n s t   s i z e _ t   n e x t L a n e N u m e r   = 
                         l a s t R o a d . G e t G i s R o a d ( ) . G e t N e x t L a n e N u m b e r ( l a s t L a n e N u m b e r ,   r o u t e 2 . r o a d I d ) ; 
 
                 b o o l   c a n P a s s I n t e r s e c t i o n ; 
 
                 i n t e r s e c t i o n . C a n E n t e r T h e R o a d ( 
                         c u r r e n t T i m e , 
                         * t h i s , 
                         r o u t e 1 . o u t g o i n g T u r n T y p e , 
                         r o u t e 1 . r o a d I d , 
                         r o u t e 2 . r o a d I d , 
                         c a n P a s s I n t e r s e c t i o n , 
                         r o u t e 2 . e n t r a n c e E n a b l e d T i m e ) ; 
 
                 c o n s t   b o o l   n e x t R o a d H a s E n o u g h C a p a c i t y   = 
                         n e x t R o a d . A l l o w e d I n c o m i n g V e h i c l e ( 
                                 v e h i c l e , 
                                 n e x t L a n e N u m e r ) ; 
 
                 c o n s t   b o o l   i s S t o p V e r t e x   = 
                         ( * t h i s ) . I s S t o p P o i n t ( r o u t e 1 . o u t g o i n g V e r t e x I d ) ; 
 
                 i f   ( i s S t o p V e r t e x )   { 
                         d i s t a n c e T o S t o p   + =   v e h i c l e . G e t H a l f B o d y L e n g t h ( )   +   v e h i c l e . G e t V e h i c l e C o n s t a n t ( ) . m i n V e h i c l e G a p ; 
                         f r o n t V e h i c l e V e l o c i t y   =   0 ; 
                         m i n D i s t a n c e T o F r o n t V e h i c l e   =   0 ; 
                         f o u n d S t o p P o i n t   =   t r u e ; 
 
                 }   e l s e   i f   ( s e e i n g A P e d e s t r i a n   | | 
                                       ! c a n P a s s I n t e r s e c t i o n   | | 
                                       ! n e x t R o a d H a s E n o u g h C a p a c i t y )   { 
 
                         / /   a t   l e a s t ,   s t o p   s h o r t   o f   i n t e r s e c t i o n 
                         f r o n t V e h i c l e V e l o c i t y   =   0 ; 
                         m i n D i s t a n c e T o F r o n t V e h i c l e   =   0 ; 
                         f o u n d S t o p P o i n t   =   t r u e ; 
 
                 }   e l s e   i f   ( n e x t R o a d . H a s V e h i c l e ( n e x t L a n e N u m e r ) )   { 
 
                         c o n s t   V e h i c l e &   t a i l V e h i c l e   = 
                                 n e x t R o a d . G e t T a i l V e h i c l e ( n e x t L a n e N u m e r ) ; 
 
                         c o n s t   d o u b l e   i n t e r s e c t i o n T o T a i l D i s t a n c f e   = 
                                 i n t e r s e c t i o n . r e f . G e t V e r t e x ( ) . D i s t a n c e T o ( 
                                         t a i l V e h i c l e . G e t P o s i t i o n ( ) ) ; 
 
                         d i s t a n c e T o S t o p   + =   i n t e r s e c t i o n T o T a i l D i s t a n c f e ; 
                         f r o n t V e h i c l e V e l o c i t y   =   t a i l V e h i c l e . G e t V e l o c i t y M e t e r s P e r S e c ( ) ; 
                         f o u n d S t o p P o i n t   =   t r u e ; 
 
                 }   e l s e   { 
                         d i s t a n c e T o S t o p   + =   n e x t R o a d . G e t R o a d L e n g t h ( ) ; 
 
                         i f   ( r o u t e 1 . o u t g o i n g T u r n T y p e . d i r e c t i o n   ! =   R O A D _ T U R N _ S T R A I G H T )   { 
                                 n u m b e r V e h i c l e R o u t e T u r n s + + ; 
                         } 
                 } 
 
                 l a s t L a n e N u m b e r   =   n e x t L a n e N u m e r ; 
         } 
 
         i f   ( ! f o u n d S t o p P o i n t )   { 
                 d i s t a n c e T o S t o p   =   D B L _ M A X ; 
         } 
 } 
 
 b o o l   V e h i c l e D r i v e r B e h a v i o r : : Y i e l d R o a d T o ( 
         c o n s t   V e h i c l e &   o t h e r V e h i c l e , 
         c o n s t   d o u b l e   y i e l d D i s t a n c e T i m e S e c )   c o n s t 
 { 
         i f   ( o t h e r V e h i c l e . G e t V e l o c i t y M e t e r s P e r S e c ( )   = =   0 )   { 
                 r e t u r n   f a l s e ; 
         } 
 
         c o n s t   V e h i c l e &   v e h i c l e   =   * v e h i c l e P t r ; 
         c o n s t   d o u b l e   d i s t a n c e T o I n t e r s e c t i o n   =   v e h i c l e . G e t D i s t a n c e T o I n t e r s e c t i o n ( ) ; 
         c o n s t   d o u b l e   m i n V e l o c i t y A t I n t e r s e c t i o n   =   1 ; 
         c o n s t   d o u b l e   v e h i c l e V e l o c i t y   =   s t d : : m a x ( m i n V e l o c i t y A t I n t e r s e c t i o n ,   v e h i c l e . G e t V e l o c i t y M e t e r s P e r S e c ( ) ) ; 
 
         c o n s t   d o u b l e   o t h e r D i s t a n c e T o I n t e r s e c t i o n   =   o t h e r V e h i c l e . G e t D i s t a n c e T o I n t e r s e c t i o n ( ) ; 
         c o n s t   d o u b l e   o t h e r V e l o c i t y   =   s t d : : m a x ( m i n V e l o c i t y A t I n t e r s e c t i o n ,   o t h e r V e h i c l e . G e t V e l o c i t y M e t e r s P e r S e c ( ) ) ; 
 
         d o u b l e   t i m e S e c T o I n t e r s e c t i o n   =   0 . 0 ; 
         d o u b l e   o t h e r T i m e S e c T o I n t e r s e c t i o n   =   0 . 0 ; 
 
         i f   ( v e h i c l e V e l o c i t y   >   0 )   { 
                 i f   ( d i s t a n c e T o I n t e r s e c t i o n   > =   v e h i c l e . G e t H a l f B o d y L e n g t h ( ) )   { 
                         t i m e S e c T o I n t e r s e c t i o n   =   ( d i s t a n c e T o I n t e r s e c t i o n   -   v e h i c l e . G e t H a l f B o d y L e n g t h ( ) )   /   v e h i c l e V e l o c i t y ; 
                 } 
         } 
 
         i f   ( o t h e r V e l o c i t y   >   0 )   { 
                 i f   ( o t h e r D i s t a n c e T o I n t e r s e c t i o n   > =   o t h e r V e h i c l e . G e t H a l f B o d y L e n g t h ( ) )   { 
                         o t h e r T i m e S e c T o I n t e r s e c t i o n   =   ( o t h e r D i s t a n c e T o I n t e r s e c t i o n   -   o t h e r V e h i c l e . G e t H a l f B o d y L e n g t h ( ) )   /   o t h e r V e l o c i t y ; 
                 } 
         } 
 
         i f   ( t i m e S e c T o I n t e r s e c t i o n   -   o t h e r T i m e S e c T o I n t e r s e c t i o n   >   y i e l d D i s t a n c e T i m e S e c )   { 
                 r e t u r n   t r u e ; 
         } 
 
         / /   O t h e r   v e h i c l e   w i l l   p a s s   t h e   i n t e r s e c t i o n   f i r s t . 
         i f   ( o t h e r T i m e S e c T o I n t e r s e c t i o n   <   t i m e S e c T o I n t e r s e c t i o n )   { 
                 i f   ( o t h e r T i m e S e c T o I n t e r s e c t i o n   <   v e h i c l e . G e t V e h i c l e C o n s t a n t ( ) . o t h e r V e h i c l e E n t r a n c e T i m e )   { 
                         r e t u r n   t r u e ; 
                 } 
         } 
 
         r e t u r n   f a l s e ; 
 } 
 
 v o i d   V e h i c l e D r i v e r B e h a v i o r : : R e s t a r t R u n ( ) 
 { 
         i f   ( ! r o u t e s . e m p t y ( ) )   { 
                 V e h i c l e &   v e h i c l e   =   * v e h i c l e P t r ; 
 
                 i f   ( ! r o u t e s . e m p t y ( ) )   { 
                         c o n s t   V e h i c l e R o u t e &   n e x t R o u t e   =   r o u t e s . f r o n t ( ) ; 
                         c o n s t   A g e n t R o a d &   a g e n t R o a d   =   t h e A g e n t G i s P t r - > G e t A g e n t R o a d ( n e x t R o u t e . r o a d I d ) ; 
                         c o n s t   R o a d &   r o a d   =   a g e n t R o a d . G e t G i s R o a d ( ) ; 
 
                         c u r r e n t L a n e N u m b e r   = 
                                 r o a d . G e t N e a r e s t O u t g o i n g L a n e N u m b e r ( r e s o u r c e . L a s t V e r t e x I d ( ) ,   r e s o u r c e . P o s i t i o n ( ) ) ; 
 
                         v e h i c l e . S e t N e x t L a n e N u m b e r ( c u r r e n t L a n e N u m b e r ) ; 
                         v e h i c l e . S e t N e x t R o a d I d ( n e x t R o u t e . r o a d I d ) ; 
                         v e h i c l e . S e t N e x t T u r n T y p e ( n e x t R o u t e . o u t g o i n g T u r n T y p e ) ; 
 
                         c o n s t   d o u b l e   c o n g e s t i o n   = 
                                 a g e n t R o a d . C a l c u l a t e V e h i c l e C o n g e s t i o n ( c u r r e n t L a n e N u m b e r ) ; 
 
                         r e s o u r c e . S e t C o n g e s t i o n ( c o n g e s t i o n ) ; 
                         r e s o u r c e . S e t D e s i r e d N e x t P o s i t i o n I d ( G I S _ R O A D ,   n e x t R o u t e . r o a d I d ) ; 
                 } 
         } 
 } 
 
 v o i d   V e h i c l e D r i v e r B e h a v i o r : : E n d B e h a v i o r A t V i a P o i n t ( c o n s t   s h a r e d _ p t r < A g e n t R o u t e > &   n e x t R o u t e P t r ) 
 { 
         r o u t e P t r . r e s e t ( n e w   A g e n t R o u t e ( ) ) ; 
 
         v i e w d R o u t e N u m b e r   =   0 ; 
 } 
 
 V e r t e x I d T y p e   V e h i c l e D r i v e r B e h a v i o r : : G e t V i a P o i n t V e r t e x I d ( )   c o n s t 
 { 
         i f   ( ! r o u t e s . e m p t y ( ) )   { 
                 c o n s t   V e h i c l e R o u t e &   c u r r e n t R o u t e   =   r o u t e s . f r o n t ( ) ; 
                 c o n s t   d o u b l e   e n o u g h S l o w V e l o c i t y   =   1 ; / / m / s 
 
                 i f   ( v e l o c i t y   <   e n o u g h S l o w V e l o c i t y )   { 
                         r e t u r n   c u r r e n t R o u t e . o u t g o i n g V e r t e x I d ; 
                 } 
 
                 r e t u r n   r o u t e s . b a c k ( ) . o u t g o i n g V e r t e x I d ; 
         } 
 
         r e t u r n   r e s o u r c e . L a s t V e r t e x I d ( ) ; 
 } 
 
 b o o l   V e h i c l e D r i v e r B e h a v i o r : : I s A c c e p t a b l e R o u t e C h a n g e ( c o n s t   A g e n t R o u t e &   r o u t e )   c o n s t 
 { 
         r e t u r n   ( r o u t e . b e h a v i o r   = =   A G E N T _ B E H A V I O R _ V E H I C L E ) ; 
 } 
 
 v o i d   V e h i c l e D r i v e r B e h a v i o r : : C h a n g e R o u t e ( c o n s t   s h a r e d _ p t r < A g e n t R o u t e > &   n e w R o u t e P t r ) 
 { 
         r o u t e P t r   =   n e w R o u t e P t r ; 
 
         v i e w d R o u t e N u m b e r   =   0 ; 
 
         i f   ( r o u t e s . e m p t y ( ) )   { 
                 ( * t h i s ) . A s s i g n F i r s t R o u t e ( ) ; 
         } 
 } 
 
 v o i d   V e h i c l e D r i v e r B e h a v i o r : : F o r c e S t o p V e h i c l e ( ) 
 { 
         r o u t e s . c l e a r ( ) ; 
 
         p a s s i n g I n t e r s e c t i o n   =   f a l s e ; 
         r o u t e s . c l e a r ( ) ; 
         r e m a i n i n g D i s t a n c e T o I n t e r s e c t i o n   =   0 ; 
         r e m a i n i n g S h o r t S t o p T i m e   =   Z E R O _ T I M E ; 
 
         r e m a i n i n g P a t h D i s t a n c e   =   D B L _ M A X ; 
 
         v i e w d R o u t e N u m b e r   =   0 ; 
 } 
 
 v o i d   V e h i c l e D r i v e r B e h a v i o r : : T r y I n t e r n a l R o u t e C h a n g e ( 
         c o n s t   V e r t e x I d T y p e &   s t a r t V e r t e x I d , 
         c o n s t   V e r t e x I d T y p e &   e n d V e r t e x I d , 
         b o o l &   f o u n d R o u t e ) 
 { 
         i f   ( s t a r t V e r t e x I d   = =   e n d V e r t e x I d )   { 
                 f o u n d R o u t e   =   t r u e ; 
                 r e t u r n ; 
         } 
 
         s h a r e d _ p t r < A g e n t R o u t e >   n e w R o u t e P t r ( n e w   A g e n t R o u t e ( ) ) ; 
 
         a s s e r t ( r o u t e P t r   ! =   n u l l p t r ) ; 
         t h e A g e n t G i s P t r - > S e a r c h R o a d R o u t e ( 
                 r e s o u r c e , 
                 s t a r t V e r t e x I d , 
                 e n d V e r t e x I d , 
                 ( * t h i s ) . G e t B e h a v i o r T y p e ( ) , 
                 * n e w R o u t e P t r ) ; 
 
         i f   ( n e w R o u t e P t r - > I s E m p t y ( ) )   { 
 
                 f o u n d R o u t e   =   f a l s e ; 
 
         }   e l s e   { 
                 r o u t e P t r   =   n e w R o u t e P t r ; 
                 v i e w d R o u t e N u m b e r   =   0 ; 
 
                 i f   ( ! r o u t e s . e m p t y ( ) )   { 
                         / /   s p e c i a l   c a s e   f o r   s l o w   v e h i c l e   s p e e d 
 
                         i f   ( r o u t e s . f r o n t ( ) . o u t g o i n g V e r t e x I d   = =   s t a r t V e r t e x I d )   { 
                                 w h i l e   ( r o u t e s . s i z e ( )   > =   2 )   { 
                                         r o u t e s . p o p _ b a c k ( ) ; 
                                 } 
                         } 
                 } 
 
                 i f   ( r o u t e s . e m p t y ( ) )   { 
                         ( * t h i s ) . A s s i g n F i r s t R o u t e ( ) ; 
                 } 
 
                 f o u n d R o u t e   =   t r u e ; 
         } 
 } 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 B u s D r i v e r B e h a v i o r : : B u s D r i v e r B e h a v i o r ( 
         c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   i n i t A g e n t G i s P t r , 
         c o n s t   s h a r e d _ p t r < P u b l i c V e h i c l e T a b l e > &   i n i t P u b l i c V e h i c l e T a b l e P t r , 
         c o n s t   A g e n t R e s o u r c e &   i n i t R e s o u r c e , 
         c o n s t   s h a r e d _ p t r < V e h i c l e > &   i n i t V e h i c l e P t r , 
         c o n s t   s h a r e d _ p t r < B u s > &   i n i t B u s P t r , 
         c o n s t   S i m T i m e &   i n i t M i n S h o r t S t o p T i m e ) 
         : 
         V e h i c l e D r i v e r B e h a v i o r ( 
                 i n i t A g e n t G i s P t r , 
                 i n i t P u b l i c V e h i c l e T a b l e P t r , 
                 i n i t B u s P t r - > r o u t e P t r , 
                 i n i t R e s o u r c e , 
                 i n i t V e h i c l e P t r , 
                 i n i t M i n S h o r t S t o p T i m e ) , 
         b u s P t r ( i n i t B u s P t r ) 
 { 
         v e h i c l e P t r - > S e t V e h i c l e C o n s t a n t ( 
                 r e s o u r c e . M a k e V e h i c l e C o n s t a n t ( b u s P t r - > G e t V e h i c l e F a m i l y ( ) . l e n g t h M e t e r s ) ) ; 
 
         c o n s t   B u s S t o p I d T y p e   b u s S t o p I d   =   b u s P t r - > G e t S t a r t B u s S t o p I d ( ) ; 
         c o n s t   S i m T i m e   c u r r e n t T i m e   =   r e s o u r c e . C u r r e n t T i m e ( ) ; 
 
         r e s o u r c e . S e t C u r r e n t P o s i t i o n I d ( G I S _ B U S S T O P ,   b u s S t o p I d ) ; 
 
         t h e A g e n t G i s P t r - > E n t e r T o B u s S t o p ( r e s o u r c e ,   b u s S t o p I d ,   b u s P t r ) ; 
 
         r e m a i n i n g S h o r t S t o p T i m e   = 
                 s t d : : m a x ( m i n S h o r t S t o p T i m e ,   b u s P t r - > G e t D e p a r t u r e T i m e ( c u r r e n t T i m e )   -   c u r r e n t T i m e ) ; 
 } 
 
 B u s D r i v e r B e h a v i o r : : ~ B u s D r i v e r B e h a v i o r ( ) 
 { 
         v e h i c l e P t r - > r o a d I d   =   I N V A L I D _ V A R I A N T _ I D ; 
         v e h i c l e P t r - > n e x t R o a d I d   =   v e h i c l e P t r - > r o a d I d ; 
 } 
 
 b o o l   B u s D r i v e r B e h a v i o r : : H a s F i n i s h e d ( )   c o n s t 
 { 
         r e t u r n   ( ! b u s P t r - > H a s A n A g e n t ( )   & & 
                         b u s P t r - > A r r i v e d A t T h e L a s t B u s S t o p ( r e s o u r c e . C u r r e n t T i m e ( ) ) ) ; 
 } 
 
 v o i d   B u s D r i v e r B e h a v i o r : : I n c r e m e n t T i m e S t e p ( c o n s t   S i m T i m e &   t i m e S t e p ) 
 { 
         i f   ( r e m a i n i n g S h o r t S t o p T i m e   >   Z E R O _ T I M E )   { 
                 c o n s t   S i m T i m e   c u r r e n t T i m e   =   r e s o u r c e . C u r r e n t T i m e ( ) ; 
 
                 r e m a i n i n g S h o r t S t o p T i m e   = 
                         s t d : : m a x ( r e m a i n i n g S h o r t S t o p T i m e ,   b u s P t r - > G e t D e p a r t u r e T i m e ( c u r r e n t T i m e )   -   c u r r e n t T i m e ) ; 
         } 
 
         ( * t h i s ) . V e h i c l e D r i v e r B e h a v i o r : : I n c r e m e n t T i m e S t e p ( t i m e S t e p ) ; 
 } 
 
 b o o l   B u s D r i v e r B e h a v i o r : : I s S t o p P o i n t ( c o n s t   V e r t e x I d T y p e &   v e r t e x I d )   c o n s t 
 { 
         c o n s t   B u s S t o p I d T y p e   n e x t B u s S t o p I d   =   b u s P t r - > G e t N e x t B u s S t o p I d ( ) ; 
 
         r e t u r n   ( t h e A g e n t G i s P t r - > G e t A g e n t B u s S t o p ( n e x t B u s S t o p I d ) . r e f . G e t V e r t e x I d ( )   = =   v e r t e x I d ) ; 
 } 
 
 v o i d   B u s D r i v e r B e h a v i o r : : A r r i v e d A t V e r t e x ( c o n s t   V e r t e x I d T y p e &   v e r t e x I d ) 
 { 
         i f   ( b u s P t r - > G e t N e x t B u s S t o p V e r t e x I d ( )   = =   v e r t e x I d )   { 
 
                 c o n s t   B u s S t o p I d T y p e   b u s S t o p I d   =   b u s P t r - > G e t N e x t B u s S t o p I d ( ) ; 
                 c o n s t   S i m T i m e   c u r r e n t T i m e   =   r e s o u r c e . C u r r e n t T i m e ( ) ; 
 
                 ( * t h i s ) . P a r k i n g V e h i c l e I f P o s s i b l e ( 
                         v e r t e x I d , 
                         s t d : : m a x ( m i n S h o r t S t o p T i m e ,   b u s P t r - > G e t D e p a r t u r e T i m e ( c u r r e n t T i m e )   -   c u r r e n t T i m e ) ) ; 
 
                 b u s P t r - > A r r i v e d A t B u s S t o p ( c u r r e n t T i m e ) ; 
 
                 t h e A g e n t G i s P t r - > E n t e r T o B u s S t o p ( r e s o u r c e ,   b u s S t o p I d ,   b u s P t r ) ; 
 
         } / / i f / / 
 } 
 
 v o i d   B u s D r i v e r B e h a v i o r : : T r y I n t e r n a l R o u t e C h a n g e ( 
         c o n s t   V e r t e x I d T y p e &   s t a r t V e r t e x I d , 
         c o n s t   V e r t e x I d T y p e &   e n d V e r t e x I d , 
         b o o l &   f o u n d R o u t e ) 
 { 
         i f   ( r o u t e P t r - > I s E m p t y ( ) )   { 
                 f o u n d R o u t e   =   f a l s e ; 
                 r e t u r n ; 
         } 
 
         c o n s t   R o a d L a y e r &   r o a d L a y e r   = 
                 * t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) . G e t R o a d L a y e r P t r ( ) ; 
 
         v e c t o r < V e r t e x I d T y p e >   v e r t e x I d s ; 
 
         v e r t e x I d s . p u s h _ b a c k ( s t a r t V e r t e x I d ) ; 
 
         s h a r e d _ p t r < A g e n t R o u t e >   n e w B u s R o u t e P t r ( n e w   A g e n t R o u t e ( ) ) ; 
 
         f o r ( s i z e _ t   i   =   b u s P t r - > G e t N e x t S t o p N u m b e r ( ) ;   i   <   b u s P t r - > G e t N u m b e r O f S t o p s ( ) ;   i + + )   { 
                 v e r t e x I d s . p u s h _ b a c k ( r o a d L a y e r . G e t B u s S t o p ( b u s P t r - > G e t B u s S t o p I d ( i ) ) . G e t V e r t e x I d ( ) ) ; 
         } 
 
         f o r ( s i z e _ t   i   =   0 ;   ( i   +   1 )   <   v e r t e x I d s . s i z e ( ) ;   i + + )   { 
                 c o n s t   V e r t e x I d T y p e &   r o u t e S t a r t V e r t e x I d   =   v e r t e x I d s [ i ] ; 
                 c o n s t   V e r t e x I d T y p e &   r o u t e E n d V e r t e x I d   =   v e r t e x I d s [ i + 1 ] ; 
 
                 A g e n t R o u t e   a R o u t e ; 
 
                 t h e A g e n t G i s P t r - > S e a r c h R o a d R o u t e ( 
                         r e s o u r c e , 
                         r o u t e S t a r t V e r t e x I d , 
                         r o u t e E n d V e r t e x I d , 
                         A G E N T _ B E H A V I O R _ B U S , 
                         a R o u t e ) ; 
 
                 i f   ( a R o u t e . I s E m p t y ( ) )   { 
                         f o u n d R o u t e   =   f a l s e ; 
                         r e t u r n ; 
                 } 
 
                 n e w B u s R o u t e P t r - > r o a d R o u t e s . i n s e r t ( 
                         n e w B u s R o u t e P t r - > r o a d R o u t e s . e n d ( ) , 
                         a R o u t e . r o a d R o u t e s . b e g i n ( ) , 
                         a R o u t e . r o a d R o u t e s . e n d ( ) ) ; 
         } 
 
         r o u t e P t r   =   n e w B u s R o u t e P t r ; 
         b u s P t r - > r o u t e P t r   =   n e w B u s R o u t e P t r ; 
 
         v i e w d R o u t e N u m b e r   =   0 ; 
 
         i f   ( r o u t e s . e m p t y ( ) )   { 
                 ( * t h i s ) . A s s i g n F i r s t R o u t e ( ) ; 
         } 
 
         f o u n d R o u t e   =   t r u e ; 
 } 
 
 V e r t e x I d T y p e   B u s D r i v e r B e h a v i o r : : G e t F i x e d D e s t i n a t i o n V e r t e x I d ( )   c o n s t 
 { 
         r e t u r n   r o u t e P t r - > G e t D e s t V e r t e x I d ( ) ; 
 } 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 T r a i n D r i v e r B e h a v i o r : : T r a i n D r i v e r B e h a v i o r ( 
         c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   i n i t A g e n t G i s P t r , 
         c o n s t   s h a r e d _ p t r < P u b l i c V e h i c l e T a b l e > &   i n i t P u b l i c V e h i c l e T a b l e P t r , 
         c o n s t   A g e n t R e s o u r c e &   i n i t R e s o u r c e , 
         c o n s t   s h a r e d _ p t r < T r a i n > &   i n i t T r a i n P t r ) 
         : 
         A g e n t B e h a v i o r ( i n i t A g e n t G i s P t r ,   i n i t P u b l i c V e h i c l e T a b l e P t r ,     s h a r e d _ p t r < A g e n t R o u t e > ( n e w   A g e n t R o u t e ( ) ) ,   i n i t R e s o u r c e ) , 
         t r a i n P t r ( i n i t T r a i n P t r ) 
 { 
 } 
 
 T r a i n D r i v e r B e h a v i o r : : ~ T r a i n D r i v e r B e h a v i o r ( ) 
 { 
 } 
 
 b o o l   T r a i n D r i v e r B e h a v i o r : : H a s F i n i s h e d ( )   c o n s t 
 { 
         c o n s t   S i m T i m e   c u r r e n t T i m e   =   r e s o u r c e . C u r r e n t T i m e ( ) ; 
         c o n s t   G i s S u b s y s t e m &   s u b s y s t e m   =   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) ; 
         c o n s t   R a i l R o a d L a y e r &   r a i l R o a d L a y e r   =   * s u b s y s t e m . G e t R a i l R o a d L a y e r P t r ( ) ; 
 
         r e t u r n   ( r a i l R o a d L a y e r . I s R a i l R o a d L i n e A v a i l a b l e ( t r a i n P t r - > G e t R a i l R o a d L i n e I d ( ) )   & & 
                         c u r r e n t T i m e   > =   t r a i n P t r - > G e t G a r b a g e T i m e ( ) ) ; 
 } 
 
 v o i d   T r a i n D r i v e r B e h a v i o r : : I n c r e m e n t T i m e S t e p ( c o n s t   S i m T i m e &   t i m e S t e p ) 
 { 
         c o n s t   G i s S u b s y s t e m &   s u b s y s t e m   =   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) ; 
         c o n s t   R a i l R o a d L a y e r &   r a i l R o a d L a y e r   =   * s u b s y s t e m . G e t R a i l R o a d L a y e r P t r ( ) ; 
 
         i f   ( ! r a i l R o a d L a y e r . I s R a i l R o a d L i n e A v a i l a b l e ( t r a i n P t r - > G e t R a i l R o a d L i n e I d ( ) ) )   { 
                 r e s o u r c e . S e t P o s i t i o n ( r e s o u r c e . P o s i t i o n ( ) ) ; 
                 r e t u r n ; 
         } 
 
         c o n s t   S i m T i m e   c u r r e n t T i m e   =   r e s o u r c e . C u r r e n t T i m e ( ) ; 
 
         t r a i n P t r - > S e t T i m e T o ( c u r r e n t T i m e ) ; 
 
         r e s o u r c e . S e t P o s i t i o n ( t r a i n P t r - > G e t P o s i t i o n ( ) ) ; 
 } 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 T a x i D r i v e r B e h a v i o r : : T a x i D r i v e r B e h a v i o r ( 
         c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   i n i t A g e n t G i s P t r , 
         c o n s t   s h a r e d _ p t r < P u b l i c V e h i c l e T a b l e > &   i n i t P u b l i c V e h i c l e T a b l e P t r , 
         c o n s t   A g e n t R e s o u r c e &   i n i t R e s o u r c e , 
         c o n s t   s h a r e d _ p t r < T a x i > &   i n i t T a x i P t r , 
         c o n s t   S i m T i m e &   i n i t M i n S h o r t S t o p T i m e ) 
         : 
         V e h i c l e D r i v e r B e h a v i o r ( 
                 i n i t A g e n t G i s P t r , 
                 i n i t P u b l i c V e h i c l e T a b l e P t r , 
                 s h a r e d _ p t r < A g e n t R o u t e > ( ) , 
                 i n i t R e s o u r c e , 
                 i n i t T a x i P t r , 
                 i n i t M i n S h o r t S t o p T i m e ) , 
         s t a t e ( D R I V E R _ S T A T E _ A T _ H O M E ) , 
         t a x i P t r ( i n i t T a x i P t r ) 
 { 
         v e h i c l e P t r - > S e t V e h i c l e C o n s t a n t ( r e s o u r c e . M a k e V e h i c l e C o n s t a n t ( ) ) ; 
 } 
 
 T a x i D r i v e r B e h a v i o r : : ~ T a x i D r i v e r B e h a v i o r ( ) 
 { 
         v e h i c l e P t r - > S e t N e x t R o a d I d ( I N V A L I D _ V A R I A N T _ I D ) ; 
 } 
 
 b o o l   T a x i D r i v e r B e h a v i o r : : H a s N o C u s t o m e r A n d R e s e r v a t i o n A t H o m e ( )   c o n s t 
 { 
         r e t u r n   ( ! t a x i P t r - > C o n t a i n s C u s t o m e r ( )   & & 
                         ! t a x i P t r - > H a s R e s e r v a t i o n ( )   & & 
                         r e s o u r c e . L a s t V e r t e x I d ( )   = =   t a x i P t r - > G e t H o m e V e r t e x I d ( )   & & 
                         s t a t e   = =   D R I V E R _ S T A T E _ A T _ H O M E ) ; 
 } 
 
 b o o l   T a x i D r i v e r B e h a v i o r : : I s S t o p P o i n t ( c o n s t   V e r t e x I d T y p e &   v e r t e x I d )   c o n s t 
 { 
         r e t u r n   ( v e r t e x I d   = =   n e x t S t o p V e r t e x I d ) ; 
 } 
 
 v o i d   T a x i D r i v e r B e h a v i o r : : R e s t a r t R u n ( ) 
 { 
         i f   ( n e x t S t o p V e r t e x I d   = =   r e s o u r c e . L a s t V e r t e x I d ( ) )   { 
 
                 r e s o u r c e . O u t p u t T r a c e ( " D e p a r t e d " ) ; 
 
                 ( * t h i s ) . D e c i d e R o u t e ( ) ; 
 
                 ( * t h i s ) . A s s i g n F i r s t R o u t e ( ) ; 
 
         }   e l s e   { 
                 V e h i c l e D r i v e r B e h a v i o r : : R e s t a r t R u n ( ) ; 
         } 
 } 
 
 v o i d   T a x i D r i v e r B e h a v i o r : : I n c r e m e n t T i m e S t e p ( c o n s t   S i m T i m e &   t i m e S t e p ) 
 { 
         i f   ( ( * t h i s ) . H a s N o C u s t o m e r A n d R e s e r v a t i o n A t H o m e ( ) )   { 
 
                 r e s o u r c e . S e t P o s i t i o n ( r e s o u r c e . P o s i t i o n ( ) ) ; 
                 r e t u r n ; 
         } 
 
         i f   ( s t a t e   = =   D R I V E R _ S T A T E _ A T _ H O M E )   { 
 
                 i f   ( t a x i P t r - > H a s R e s e r v a t i o n ( ) )   { 
                         ( * t h i s ) . D e c i d e R o u t e ( ) ; 
                 } 
 
         }   e l s e   i f   ( s t a t e   = =   D R I V E R _ S T A T E _ T R A N S P O R T )   { 
 
                 i f   ( ! t a x i P t r - > C o n t a i n s C u s t o m e r ( ) )   { 
 
                         ( * t h i s ) . D e c i d e R o u t e ( ) ; 
 
                 }   e l s e   i f   ( t a x i P t r - > H a s C u s t o m e r R e q u e s t R o u t e ( ) )   { 
 
                         ( * t h i s ) . D e c i d e R o u t e ( ) ; 
                 } 
         } 
 
         ( * t h i s ) . V e h i c l e D r i v e r B e h a v i o r : : I n c r e m e n t T i m e S t e p ( t i m e S t e p ) ; 
 } 
 
 v o i d   T a x i D r i v e r B e h a v i o r : : D e c i d e R o u t e ( ) 
 { 
         c o n s t   V e r t e x I d T y p e   v i a p o i n t V e r t e x I d   =   ( * t h i s ) . G e t V i a P o i n t V e r t e x I d ( ) ; 
 
         s h a r e d _ p t r < A g e n t R o u t e >   n e w R o u t e P t r ; 
 
         i f   ( t a x i P t r - > C o n t a i n s C u s t o m e r ( ) )   { 
                 s t a t e   =   D R I V E R _ S T A T E _ T R A N S P O R T ; 
 
                 a s s e r t ( t a x i P t r - > H a s C u s t o m e r R e q u e s t R o u t e ( ) ) ; 
                 n e w R o u t e P t r   =   t a x i P t r - > T a k e C u s t o m e r R e q u e s t R o u t e ( ) ; 
 
                 n e x t S t o p V e r t e x I d   =   n e w R o u t e P t r - > G e t D e s t V e r t e x I d ( ) ; 
 
         }   e l s e   { 
                 i f   ( t a x i P t r - > H a s R e s e r v a t i o n ( ) )   { 
 
                         s t a t e   =   D R I V E R _ S T A T E _ G O _ T O _ C U S T O M E R ; 
                         n e x t S t o p V e r t e x I d   =   t a x i P t r - > G e t R e s e r v e d C u s t o m e r ( ) . L a s t V e r t e x I d ( ) ; 
 
                 }   e l s e   i f   ( s t a t e   = =   D R I V E R _ S T A T E _ A T _ H O M E )   { 
 
                         r e t u r n ; 
 
                 }   e l s e   { 
                         s t a t e   =   D R I V E R _ S T A T E _ G O _ B A C K _ H O M E ; 
                         n e x t S t o p V e r t e x I d   =   t a x i P t r - > G e t H o m e V e r t e x I d ( ) ; 
                 } 
 
                 n e w R o u t e P t r . r e s e t ( n e w   A g e n t R o u t e ( ) ) ; 
 
                 t h e A g e n t G i s P t r - > S e a r c h R o a d R o u t e ( 
                         r e s o u r c e , 
                         v i a p o i n t V e r t e x I d , 
                         n e x t S t o p V e r t e x I d , 
                         A G E N T _ B E H A V I O R _ T A X I , 
                         * n e w R o u t e P t r ) ; 
         } 
 
         i f   ( s t a t e   = =   D R I V E R _ S T A T E _ T R A N S P O R T )   { 
                 r e s o u r c e . O u t p u t T r a c e ( " R o u t e T o T r a n s p o r t   "   +   n e w R o u t e P t r - > C o n v e r t T o S t r i n g ( ) ) ; 
         }   e l s e   i f   ( s t a t e   = =   D R I V E R _ S T A T E _ G O _ T O _ C U S T O M E R )   { 
                 r e s o u r c e . O u t p u t T r a c e ( " R o u t e T o C u s t o m e r   "   +   n e w R o u t e P t r - > C o n v e r t T o S t r i n g ( ) ) ; 
         }   e l s e   { 
                 r e s o u r c e . O u t p u t T r a c e ( " R o u t e T o H o m e   "   +   n e w R o u t e P t r - > C o n v e r t T o S t r i n g ( ) ) ; 
         } 
 
         ( * t h i s ) . C h a n g e R o u t e ( n e w R o u t e P t r ) ; 
 
         i f   ( n e x t S t o p V e r t e x I d   = =   r e s o u r c e . L a s t V e r t e x I d ( ) )   { 
                 ( * t h i s ) . A r r i v e d A t V e r t e x ( n e x t S t o p V e r t e x I d ) ; 
         } 
 } 
 
 v o i d   T a x i D r i v e r B e h a v i o r : : A r r i v e d A t V e r t e x ( c o n s t   V e r t e x I d T y p e &   v e r t e x I d ) 
 { 
         i f   ( n e x t S t o p V e r t e x I d   = =   v e r t e x I d )   { 
                 r e s o u r c e . O u t p u t T r a c e ( " A r r i v e d " ) ; 
 
                 i f   ( s t a t e   = =   D R I V E R _ S T A T E _ G O _ T O _ C U S T O M E R )   { 
 
                         ( * t h i s ) . P a r k i n g V e h i c l e F o r N e x t C u s t o m e r ( ) ; 
 
                 }   e l s e   i f   ( s t a t e   = =   D R I V E R _ S T A T E _ T R A N S P O R T )   { 
 
                         t a x i P t r - > A r r i v e d A t T h e D e s t i n a t i o n F o r C u r r e n t C u s t o m e r ( ) ; 
 
                 }   e l s e   { 
 
                         ( * t h i s ) . P a r k i n g V e h i c l e I f P o s s i b l e ( v e r t e x I d ,   m i n S h o r t S t o p T i m e ) ; 
 
                         i f   ( s t a t e   = =   D R I V E R _ S T A T E _ G O _ B A C K _ H O M E )   { 
                                 t h e A g e n t G i s P t r - > R e t u r n T a x i T o S t a t i o n ( r e s o u r c e ,   t a x i P t r ) ; 
 
                                 s t a t e   =   D R I V E R _ S T A T E _ A T _ H O M E ; 
                         } 
                 } 
         } 
 } 
 
 v o i d   T a x i D r i v e r B e h a v i o r : : P a r k i n g V e h i c l e F o r N e x t C u s t o m e r ( ) 
 { 
         i f   ( t a x i P t r - > H a s R e s e r v a t i o n ( ) )   { 
                 c o n s t   G i s P o s i t i o n I d T y p e &   p o s i t i o n I d   =   t a x i P t r - > G e t C u s t o m e r P o s i t i o n ( ) ; 
                 a s s e r t ( p o s i t i o n I d . t y p e   = =   G I S _ R O A D ) ; 
                 v e h i c l e P t r - > S e t N e x t R o a d I d ( p o s i t i o n I d . i d ) ; 
                 c u r r e n t L a n e N u m b e r   =   0 ; 
 
                 v e h i c l e P t r - > S e t N e x t L a n e N u m b e r ( c u r r e n t L a n e N u m b e r ) ; 
                 r e s o u r c e . S e t D e s i r e d N e x t P o s i t i o n I d ( p o s i t i o n I d ) ; 
                 r e m a i n i n g S h o r t S t o p T i m e   + =   s t d : : m a x ( m i n S h o r t S t o p T i m e ,   1 0   *   S E C O N D ) ; 
 
                 t a x i P t r - > S e t E n a b l e C u s t o m e r P i c k u p S t a t e ( ) ; 
 
         }   e l s e   { 
 
                 ( * t h i s ) . P a r k i n g V e h i c l e I f P o s s i b l e ( n e x t S t o p V e r t e x I d ,   m i n S h o r t S t o p T i m e ) ; 
 
         } 
 } 
 
 v o i d   T a x i D r i v e r B e h a v i o r : : T r y I n t e r n a l R o u t e C h a n g e ( 
         c o n s t   V e r t e x I d T y p e &   s t a r t V e r t e x I d , 
         c o n s t   V e r t e x I d T y p e &   e n d V e r t e x I d , 
         b o o l &   f o u n d R o u t e ) 
 { 
         V e h i c l e D r i v e r B e h a v i o r : : T r y I n t e r n a l R o u t e C h a n g e ( s t a r t V e r t e x I d ,   e n d V e r t e x I d ,   f o u n d R o u t e ) ; 
 
         n e x t S t o p V e r t e x I d   =   e n d V e r t e x I d ; 
 } 
 
 b o o l   T a x i D r i v e r B e h a v i o r : : H a s F i x e d D e s t i n a t i o n V e r t e x ( )   c o n s t 
 { 
         i f   ( s t a t e   = =   D R I V E R _ S T A T E _ G O _ T O _ C U S T O M E R   | | 
                 s t a t e   = =   D R I V E R _ S T A T E _ G O _ B A C K _ H O M E   | | 
                 s t a t e   = =   D R I V E R _ S T A T E _ A T _ H O M E )   { 
                 r e t u r n   t r u e ; 
         } 
 
         r e t u r n   f a l s e ; 
 } 
 
 V e r t e x I d T y p e   T a x i D r i v e r B e h a v i o r : : G e t F i x e d D e s t i n a t i o n V e r t e x I d ( )   c o n s t 
 { 
         a s s e r t ( ( * t h i s ) . H a s F i x e d D e s t i n a t i o n V e r t e x ( ) ) ; 
 
         r e t u r n   r o u t e P t r - > G e t D e s t V e r t e x I d ( ) ; 
 } 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 T a x i G u e s t B e h a v i o r : : T a x i G u e s t B e h a v i o r ( 
         c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   i n i t A g e n t G i s P t r , 
         c o n s t   s h a r e d _ p t r < P u b l i c V e h i c l e T a b l e > &   i n i t P u b l i c V e h i c l e T a b l e P t r , 
         c o n s t   s h a r e d _ p t r < A g e n t R o u t e > &   i n i t R o u t e P t r , 
         c o n s t   A g e n t R e s o u r c e &   i n i t R e s o u r c e ) 
         : 
         A g e n t B e h a v i o r ( i n i t A g e n t G i s P t r ,   i n i t P u b l i c V e h i c l e T a b l e P t r ,   i n i t R o u t e P t r ,   i n i t R e s o u r c e ) , 
         t o o k O f f T a x i ( f a l s e ) , 
         s u c c e e d e d T a x i C a l l ( f a l s e ) , 
         r o u t e R e c a l c u l a t i o n H a s E x e c u t e d ( f a l s e ) , 
         a r r i v a l T i m e ( r e s o u r c e . C u r r e n t T i m e ( ) ) , 
         i s O n T a x i ( f a l s e ) , 
         v i a P o i n t V e r t e x I d ( I N V A L I D _ V E R T E X _ I D ) , 
         t a x i C e n t e r I d ( I N V A L I D _ T A X I C E N T E R _ I D ) 
 { 
         / /   c a l l   t a x i 
         t h e A g e n t G i s P t r - > C a l l T a x i ( r e s o u r c e ,   A N Y _ T A X I C E N T E R _ I D ,   s u c c e e d e d T a x i C a l l ,   t a x i C e n t e r I d ) ; 
 
 
         a s s e r t ( r o u t e P t r - > I s R o a d ( ) ) ; 
 
         c o n s t   R o a d I d T y p e &   r o a d I d   =   r o u t e P t r - > r o a d R o u t e s . f r o n t ( ) . r o a d I d ; 
 
         c o n s t   G i s S u b s y s t e m &   s u b s y s t e m   =   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) ; 
         c o n s t   V e r t e x I d T y p e &   v e r t e x I d   =   r e s o u r c e . L a s t V e r t e x I d ( ) ; 
 
           i f   ( s u b s y s t e m . I s P a r k i n g V e r t e x ( v e r t e x I d ) )   { 
                 r e s o u r c e . S e t D e s i r e d N e x t P o s i t i o n I d ( G I S _ R O A D ,   s u b s y s t e m . G e t P a r k i n g R o a d I d ( v e r t e x I d ) ) ; 
           } 
           e l s e   { 
                 r e s o u r c e . S e t D e s i r e d N e x t P o s i t i o n I d ( G I S _ R O A D ,   r o a d I d ) ; 
           } 
 } 
 
 T a x i G u e s t B e h a v i o r : : ~ T a x i G u e s t B e h a v i o r ( ) 
 { 
         ( * t h i s ) . T a k e o f f T a x i ( ) ; 
 } 
 
 v o i d   T a x i G u e s t B e h a v i o r : : T a k e o f f T a x i ( ) 
 { 
         i f   ( t o o k O f f T a x i   | |   t a x i P t r   = =   n u l l p t r )   { 
                 r e t u r n ; 
         } 
 
         t o o k O f f T a x i   =   t r u e ; 
 
         t a x i P t r - > R e m o v e C u s t o m e r O r R e s e r v a t i o n ( r e s o u r c e ) ; 
 
         r e s o u r c e . R e m o v e O w n e r A g e n t ( ) ; 
 
         / /   N o t   s e t   p o s i t i o n   i d   f o r   e n t r a n c e   c h e c k   w h e n   t a k e   o f f   t a x i . 
         / /   F o l l o w i n g   b e h a v i o r   w i l l   s e t   p o s i t i o n   i d . 
 } 
 
 v o i d   T a x i G u e s t B e h a v i o r : : I n c r e m e n t T i m e S t e p ( c o n s t   S i m T i m e &   t i m e S t e p ) 
 { 
         i f   ( i s O n T a x i )   { 
 
                 c o n s t   V e r t e x I d T y p e   v e r t e x I d   =   t a x i P t r - > G e t N e x t V e r t e x I d ( ) ; 
 
                 r e s o u r c e . S e t P o s i t i o n ( t a x i P t r - > G e t N e x t P o s i t i o n ( ) ) ; 
                 r e s o u r c e . S e t V e r t e x I d ( v e r t e x I d ) ; 
 
                 i f   ( v e r t e x I d   = =   v i a P o i n t V e r t e x I d   | | 
                         t a x i P t r - > I s A r r i v e d A t T h e D e s t i n a t i o n ( ) )   { 
 
                         ( * t h i s ) . T a k e o f f T a x i ( ) ; 
                 } 
 
         }   e l s e   { 
 
                 i f   ( t a x i P t r   = =   n u l l p t r )   { 
 
                         i f   ( ! r o u t e R e c a l c u l a t i o n H a s E x e c u t e d   & & 
                                 ( ! s u c c e e d e d T a x i C a l l   | | 
                                   r e s o u r c e . C u r r e n t B e h a v i o r S p e n t T i m e ( )   >   r e s o u r c e . T a x i C a l l W a i t T i m e ( ) ) )   { 
 
                                 r o u t e R e c a l c u l a t i o n H a s E x e c u t e d   =   t r u e ; 
 
                                 i f   ( s u c c e e d e d T a x i C a l l )   { 
                                         t h e A g e n t G i s P t r - > G i v e u p T a x i C a l l ( r e s o u r c e ,   t a x i C e n t e r I d ) ; 
                                 } 
 
                                 / / s e t   t a k e   o f f   f l a g   t o   d i s c a r d ( ; f i n i s h )   c u r r e n t   b e h a v i o r 
                                 t o o k O f f T a x i   =   t r u e ; 
 
                                 / /   R e c a l c u l a t e   o t h e r   r o u t e   s o   t h a t   t h e   t a x i   c e n t e r   d i d   n o t   r e s p o n d   o v e r   w a i t i n g   t i m e . 
 
                                 s e t < A g e n t B e h a v i o r T y p e >   n o t A v a i l a b l e B e h a v i o r T y p e s ; 
 
                                 n o t A v a i l a b l e B e h a v i o r T y p e s . i n s e r t ( A G E N T _ B E H A V I O R _ T A X I ) ; 
 
                                 r e s o u r c e . R e c a l c u l a t e R o u t e W i t h N o t A v a i l a b l e B e h a v i o r S p e c i f i c a t i o n ( 
                                         n o t A v a i l a b l e B e h a v i o r T y p e s ) ; 
 
                         } 
 
                 }   e l s e   i f   ( t a x i P t r - > C a n P i c k U p ( r e s o u r c e ) )   { 
 
                         c o n s t   V e r t e x I d T y p e   v e r t e x I d   =   t a x i P t r - > G e t N e x t V e r t e x I d ( ) ; 
 
                         i f   ( v e r t e x I d   = =   v i a P o i n t V e r t e x I d )   { 
 
                                 / /   R o u t e   h a s   c h a n g e d 
                                 ( * t h i s ) . G i v e u p T a x i W a i t i n g ( ) ; 
 
                         }   e l s e   { 
                                 t a x i P t r - > T a k e O n R e s e r v e d C u s t o m e r ( r e s o u r c e ,   r o u t e P t r ) ; 
 
                                 / /   S e t   p o s i t i o n   i d   f o r   e n t r a n c e   c h e c k 
                                 / /   A d d   a n   e n t r a n c e   c a p a c i t y   t o   l a s t   r o a d . 
 
                                 r e s o u r c e . S e t D e s i r e d N e x t P o s i t i o n I d ( G i s P o s i t i o n I d T y p e ( G I S _ R O A D ,   I N V A L I D _ V A R I A N T _ I D ) ) ; 
 
                                 i s O n T a x i   =   t r u e ; 
                         } 
                 }   e l s e   i f   ( ! i s O n T a x i )   { 
 
                         i f   ( r e s o u r c e . L a s t V e r t e x I d ( )   = =   v i a P o i n t V e r t e x I d )   { 
 
                                 ( * t h i s ) . G i v e u p T a x i W a i t i n g ( ) ; 
                         } 
 
                 } 
 
                 r e s o u r c e . S e t P o s i t i o n ( r e s o u r c e . P o s i t i o n ( ) ) ; 
         } 
 } 
 
 v o i d   T a x i G u e s t B e h a v i o r : : E n d B e h a v i o r A t V i a P o i n t ( c o n s t   s h a r e d _ p t r < A g e n t R o u t e > &   n e x t R o u t e P t r ) 
 { 
         r o u t e P t r . r e s e t ( n e w   A g e n t R o u t e ( ) ) ; 
 
         i f   ( i s O n T a x i )   { 
                 t a x i P t r - > S e t C u s t o m e r R e q u e s t R o u t e ( r o u t e P t r ) ; 
         } 
 
         v i a P o i n t V e r t e x I d   =   ( * t h i s ) . G e t V i a P o i n t V e r t e x I d ( ) ; 
 } 
 
 V e r t e x I d T y p e   T a x i G u e s t B e h a v i o r : : G e t V i a P o i n t V e r t e x I d ( )   c o n s t 
 { 
         i f   ( i s O n T a x i )   { 
                 r e t u r n   t a x i P t r - > G e t V i a P o i n t V e r t e x I d ( ) ; 
         } 
 
         r e t u r n   r e s o u r c e . L a s t V e r t e x I d ( ) ; 
 } 
 
 v o i d   T a x i G u e s t B e h a v i o r : : A s s i g n T a x i ( c o n s t   s h a r e d _ p t r < T a x i > &   i n i t T a x i P t r ) 
 { 
         i f   ( t a x i P t r   = =   n u l l p t r )   { 
                 t a x i P t r   =   i n i t T a x i P t r ; 
 
                 r e s o u r c e . S e t O w n e r A g e n t ( t a x i P t r - > G e t D r i v e r A g e n t I d ( ) ) ; 
 
                 t a x i P t r - > A d d R e s e r v e d C u s t o m e r ( r e s o u r c e ) ; 
         } 
 } 
 
 b o o l   T a x i G u e s t B e h a v i o r : : I s A c c e p t a b l e R o u t e C h a n g e ( c o n s t   A g e n t R o u t e &   r o u t e )   c o n s t 
 { 
         r e t u r n   ( r o u t e . b e h a v i o r   = =   A G E N T _ B E H A V I O R _ T A X I ) ; 
 } 
 
 v o i d   T a x i G u e s t B e h a v i o r : : C h a n g e R o u t e ( c o n s t   s h a r e d _ p t r < A g e n t R o u t e > &   n e w R o u t e P t r ) 
 { 
         r o u t e P t r   =   n e w R o u t e P t r ; 
 
         i f   ( i s O n T a x i )   { 
                 t a x i P t r - > S e t C u s t o m e r R e q u e s t R o u t e ( n e w R o u t e P t r ) ; 
         } 
 
         v i a P o i n t V e r t e x I d   =   I N V A L I D _ V E R T E X _ I D ; 
 } 
 
 v o i d   T a x i G u e s t B e h a v i o r : : T r y I n t e r n a l R o u t e C h a n g e ( 
         c o n s t   V e r t e x I d T y p e &   s t a r t V e r t e x I d , 
         c o n s t   V e r t e x I d T y p e &   e n d V e r t e x I d , 
         b o o l &   f o u n d R o u t e ) 
 { 
         a s s e r t ( i s O n T a x i ) ; 
 
         i f   ( s t a r t V e r t e x I d   = =   e n d V e r t e x I d )   { 
                 f o u n d R o u t e   =   t r u e ; 
                 r e t u r n ; 
         } 
 
         s h a r e d _ p t r < A g e n t R o u t e >   n e w R o u t e P t r ( n e w   A g e n t R o u t e ( ) ) ; 
 
         a s s e r t ( r o u t e P t r   ! =   n u l l p t r ) ; 
         t h e A g e n t G i s P t r - > S e a r c h R o a d R o u t e ( 
                 r e s o u r c e , 
                 s t a r t V e r t e x I d , 
                 e n d V e r t e x I d , 
                 ( * t h i s ) . G e t B e h a v i o r T y p e ( ) , 
                 * n e w R o u t e P t r ) ; 
 
         i f   ( n e w R o u t e P t r - > I s E m p t y ( ) )   { 
 
                 f o u n d R o u t e   =   f a l s e ; 
 
         }   e l s e   { 
 
                 f o u n d R o u t e   =   t r u e ; 
 
                 ( * t h i s ) . C h a n g e R o u t e ( n e w R o u t e P t r ) ; 
         } 
 } 
 
 b o o l   T a x i G u e s t B e h a v i o r : : I s I n t e r n a l R o u t e C h a n e M o d e ( )   c o n s t 
 { 
         r e t u r n   i s O n T a x i ; 
 } 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 / /   T r a i n 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 P u b l i c V e h i c l e B e h a v i o r : : P u b l i c V e h i c l e B e h a v i o r ( 
         c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   i n i t A g e n t G i s P t r , 
         c o n s t   s h a r e d _ p t r < P u b l i c V e h i c l e T a b l e > &   i n i t P u b l i c V e h i c l e T a b l e P t r , 
         c o n s t   s h a r e d _ p t r < A g e n t R o u t e > &   i n i t R o u t e P t r , 
         c o n s t   A g e n t R e s o u r c e &   i n i t R e s o u r c e ) 
         : 
         A g e n t B e h a v i o r ( i n i t A g e n t G i s P t r ,   i n i t P u b l i c V e h i c l e T a b l e P t r ,   i n i t R o u t e P t r ,   i n i t R e s o u r c e ) , 
         d e s t P o s i t i o n I n V e h i c l e M e t e r s ( 0 ) , 
         c u r r e n t P o s i t i o n I n V e h i c l e M e t e r s ( 0 ) , 
         r e l a t i v e P o s i t i o n R a d i a n s ( 0 ) , 
         c u r r e n t S t o p N u m b e r ( 0 ) , 
         a r r i v e d A t R i d e O n S t o p ( f a l s e ) , 
         t r y R i d i n g ( f a l s e ) , 
         s t o p A r r i v a l T i m e ( I N F I N I T E _ T I M E ) , 
         v e h i c l e S c h e d u l e A r r i v a l T i m e ( I N F I N I T E _ T I M E ) , 
         v i a P o i n t V e r t e x I d ( I N V A L I D _ V E R T E X _ I D ) , 
         a n c h o r D i r e c t i o n R a d i a n s ( 0 ) 
 { 
         a s s e r t ( ! r o u t e P t r - > I s T r a n s f e r L i n e ( 0 ) ) ; 
 } 
 
 P u b l i c V e h i c l e B e h a v i o r : : ~ P u b l i c V e h i c l e B e h a v i o r ( ) 
 { 
         ( * t h i s ) . G e t D o w n V e h i c l e ( ) ; 
 } 
 
 v o i d   P u b l i c V e h i c l e B e h a v i o r : : I n c r e m e n t T i m e S t e p ( c o n s t   S i m T i m e &   t i m e S t e p ) 
 { 
         r e s o u r c e . S e t P o s i t i o n ( r e s o u r c e . P o s i t i o n ( ) ) ; 
 
         i f   ( t r y R i d i n g )   { 
 
                 t r y R i d i n g   =   f a l s e ; 
 
                 i f   ( v e h i c l e P t r - > C o n t a i n s ( r e s o u r c e ) )   { 
 
                         ( * t h i s ) . D e c i d e P o s i t i o n I n V e h i c l e ( ) ; 
 
                         r e s o u r c e . S e t O w n e r A g e n t ( v e h i c l e P t r - > G e t D r i v e r A g e n t I d ( ) ) ; 
 
                         / /   S e t   p o s i t i o n   i d   f o r   e n t r a n c e   c h e c k 
                         / /   A d d   a n   e n t r a n c e   c a p a c i t y   t o   l a s t   r o a d . 
 
                         r e s o u r c e . S e t D e s i r e d N e x t P o s i t i o n I d ( G i s P o s i t i o n I d T y p e ( G I S _ R A I L R O A D ,   I N V A L I D _ V A R I A N T _ I D ) ) ; 
 
                         r e t u r n ; 
 
                 }   e l s e   { 
                         c o n s t   P u b l i c V e h i c l e R o u t e &   v e h i c l e R o u t e   = 
                                 r o u t e P t r - > p u b l i c V e h i c l e R o u t e s . a t ( c u r r e n t S t o p N u m b e r ) ; 
 
                         i f   ( v e h i c l e P t r - > G e t V e h i c l e N u m b e r ( )   = =   v e h i c l e R o u t e . v e h i c l e N u m b e r )   { 
                                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d o m N u m b e r G e n e r a t o r   =   r e s o u r c e . G e t R a n d o m N u m b e r G e n e r a t o r ( ) ; 
 
                                 i f   ( r a n d o m N u m b e r G e n e r a t o r . G e n e r a t e R a n d o m D o u b l e ( )   <   r e s o u r c e . M i s s e d V e h i c l e P a t h Q u e r y P r o b a b i l i t y ( ) )   { 
                                         r e s o u r c e . R e c a l c u l a t e R o u t e ( v e h i c l e P t r - > G e t D e p a r t u r e T i m e ( r e s o u r c e . C u r r e n t T i m e ( ) )   +   S E C O N D ) ; 
 
                                         v e h i c l e P t r . r e s e t ( ) ; 
 
                                         r e s o u r c e . O u t p u t T r a c e ( " R o u t e   R e c a l c u l a t i o n   f o r   r e a c h i n g   a   v e h i c l e   l i m i t . " ) ; 
                                         r e t u r n ; 
                                 } 
                         } 
 
                         v e h i c l e P t r . r e s e t ( ) ; 
                 } 
         } 
 
         i f   ( ( * t h i s ) . I s O n P u b l i c V e h i c l e ( ) )   { 
 
                 ( * t h i s ) . I n c r e m e n t T i m e S t e p I n V e h i c l e ( t i m e S t e p ) ; 
 
         }   e l s e   i f   ( a r r i v e d A t R i d e O n S t o p )   { 
 
                 i f   ( v i a P o i n t V e r t e x I d   ! =   I N V A L I D _ V E R T E X _ I D )   { 
                         ( * t h i s ) . F o r c e S t o p R i d i n g ( ) ; 
                         r e t u r n ; 
                 } 
 
                 c o n s t   P u b l i c V e h i c l e R o u t e &   v e h i c l e R o u t e   = 
                         r o u t e P t r - > p u b l i c V e h i c l e R o u t e s . a t ( c u r r e n t S t o p N u m b e r ) ; 
 
                 c o n s t   G i s P o s i t i o n I d T y p e   p o s i t i o n I d   = 
                         t h e P u b l i c V e h i c l e T a b l e P t r - > G e t P o s i t i o n I d ( v e h i c l e R o u t e . o r i g S t o p I d ) ; 
 
                 / /   F i r s t ,   s e t   p o s i t i o n   i d   f o r   e n t r a n c e   c h e c k . 
                 / /   E n t r a n c e   s t a t u s   m a y   b l o c k   b e h a v i o r   e x e c u t i o n . 
 
                 i f   ( r e s o u r c e . G e t C u r r e n t P o s i t i o n I d ( )   ! =   p o s i t i o n I d )   { 
 
                         r e s o u r c e . S e t D e s i r e d N e x t P o s i t i o n I d ( p o s i t i o n I d ) ; 
 
                 }   e l s e   { 
 
                         a s s e r t ( v e h i c l e R o u t e . l i n e I d   ! =   T R A N S F E R _ L I N E _ I D ) ; 
 
                         i f   ( ! t h e P u b l i c V e h i c l e T a b l e P t r - > I s L i n e A v a i l a b l e ( v e h i c l e R o u t e . l i n e I d ) )   { 
                                 ( * t h i s ) . F o r c e S t o p R i d i n g ( ) ; 
                                 r e s o u r c e . R e c a l c u l a t e R o u t e ( ) ; 
                                 r e s o u r c e . O u t p u t T r a c e ( " R o u t e   R e c a l c u l a t i o n   f o r   n o n a v a i l a b l e   l i n e " ) ; 
                                 r e t u r n ; 
                         } 
 
                         c o n s t   S i m T i m e   c u r r e n t T i m e   =   r e s o u r c e . C u r r e n t T i m e ( ) ; 
 
                         c o n s t   d o u b l e   c o n g e s t i o n   = 
                                 t h e P u b l i c V e h i c l e T a b l e P t r - > C a l c u l a t e C o n g e s t i o n ( 
                                         v e h i c l e R o u t e . o r i g S t o p I d ) ; 
 
                         c o n s t   S i m T i m e   v e h i c l e D e l a y   = 
                                 s t d : : m a x ( Z E R O _ T I M E ,   c u r r e n t T i m e   -   v e h i c l e S c h e d u l e A r r i v a l T i m e ) ; 
 
                         r e s o u r c e . S e t C o n g e s t i o n ( c o n g e s t i o n ) ; 
 
                         i f   ( r e s o u r c e . I s P a t h Q u e r y T r i g g e r A v a i l a b l e ( c o n g e s t i o n ,   v e h i c l e D e l a y ) )   { 
 
                                 r e s o u r c e . R e c a l c u l a t e R o u t e ( ) ; 
                                 r e s o u r c e . S e t L a s t P a t h Q u e r y T r i g g e r T i m e ( ) ; 
 
                                 r e s o u r c e . O u t p u t T r a c e ( " R o u t e   R e c a l c u l a t i o n   a t   n e x t   s t e p " ) ; 
 
                         }   e l s e   i f   ( c u r r e n t T i m e   >   v e h i c l e S c h e d u l e A r r i v a l T i m e   & & 
                                               ( * t h i s ) . M i s s e d P u b l i c V e h i c l e ( ) )   { 
 
                                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d o m N u m b e r G e n e r a t o r   =   r e s o u r c e . G e t R a n d o m N u m b e r G e n e r a t o r ( ) ; 
 
                                 i f   ( r a n d o m N u m b e r G e n e r a t o r . G e n e r a t e R a n d o m D o u b l e ( )   <   r e s o u r c e . M i s s e d V e h i c l e P a t h Q u e r y P r o b a b i l i t y ( ) )   { 
                                         ( * t h i s ) . F o r c e S t o p R i d i n g ( ) ; 
                                         r e s o u r c e . R e c a l c u l a t e R o u t e ( ) ; 
                                         r e s o u r c e . S e t L a s t P a t h Q u e r y T r i g g e r T i m e ( ) ; 
                                         r e s o u r c e . O u t p u t T r a c e ( " R o u t e   R e c a l c u l a t i o n   f o r   m i s s e d   a   w a i t i n g   v e h i c l e . " ) ; 
                                 }   e l s e   { 
                                         ( * t h i s ) . R i d e O n V e h i c l e I f P o s s i b l e ( ) ; 
                                 } 
 
                         }   e l s e   { 
                                 a s s e r t ( v e h i c l e R o u t e . l i n e I d   ! =   T R A N S F E R _ L I N E _ I D ) ; 
 
                                 ( * t h i s ) . R i d e O n V e h i c l e I f P o s s i b l e ( ) ; 
                         } 
                 } 
 
         }   e l s e   i f   ( c u r r e n t P o s i t i o n I n V e h i c l e M e t e r s   >   0 )   { 
                 c o n s t   d o u b l e   w a l k D i s t a n c e M e t e r s   =   r e s o u r c e . W a l k S p e e d M e t e r s P e r S e c ( ) * d o u b l e ( t i m e S t e p ) / S E C O N D ; 
 
                 c u r r e n t P o s i t i o n I n V e h i c l e M e t e r s   =   s t d : : m a x ( 
                         0 . ,   c u r r e n t P o s i t i o n I n V e h i c l e M e t e r s   -   w a l k D i s t a n c e M e t e r s ) ; 
 
                 ( * t h i s ) . U p d a t e A n c h o r P o s i t i o n ( ) ; 
 
         }   e l s e   i f   ( c u r r e n t S t o p N u m b e r   <   r o u t e P t r - > p u b l i c V e h i c l e R o u t e s . s i z e ( ) )   { 
                 i f   ( p e d e s t r i a n P t r   = =   n u l l p t r )   { 
 
                         c o n s t   P u b l i c V e h i c l e R o u t e &   r o u t e   = 
                                 r o u t e P t r - > p u b l i c V e h i c l e R o u t e s . a t ( c u r r e n t S t o p N u m b e r ) ; 
 
                         i f   ( r o u t e . l i n e I d   = =   T R A N S F E R _ L I N E _ I D )   { 
 
                                 c o n s t   P u b l i c V e h i c l e R o u t e &   p r e v R o u t e   = 
                                         r o u t e P t r - > p u b l i c V e h i c l e R o u t e s . a t ( c u r r e n t S t o p N u m b e r   -   1 ) ; 
 
                                 c o n s t   P u b l i c V e h i c l e R o u t e &   n e x t R o u t e   = 
                                         r o u t e P t r - > p u b l i c V e h i c l e R o u t e s . a t ( c u r r e n t S t o p N u m b e r   +   1 ) ; 
 
                                 ( * t h i s ) . S e t P e d e s t r i a n B e h a v i o r T o w a r d N e x t S t o p ( 
                                         r o u t e P t r - > G e t D o w n S t o p I d ( c u r r e n t S t o p N u m b e r ) , 
                                         t h e P u b l i c V e h i c l e T a b l e P t r - > G e t D e s t V e r t e x I d ( p r e v R o u t e ) , 
                                         t h e P u b l i c V e h i c l e T a b l e P t r - > G e t O r i g E n t r a n c e V e r t e x I d ( n e x t R o u t e ,   r e s o u r c e . P o s i t i o n ( ) ) ) ; 
 
                         }   e l s e   { 
 
                                 ( * t h i s ) . S e t P e d e s t r i a n B e h a v i o r T o w a r d N e x t S t o p ( 
                                         r o u t e P t r - > G e t S t o p I d ( c u r r e n t S t o p N u m b e r ) , 
                                         r e s o u r c e . L a s t V e r t e x I d ( ) , 
                                         t h e P u b l i c V e h i c l e T a b l e P t r - > G e t O r i g E n t r a n c e V e r t e x I d ( r o u t e ,   r e s o u r c e . P o s i t i o n ( ) ) ) ; 
                         } 
                 } 
                 p e d e s t r i a n P t r - > I n c r e m e n t T i m e S t e p ( t i m e S t e p ) ; 
 
                 i f   ( p e d e s t r i a n P t r - > H a s F i n i s h e d ( ) )   { 
                         a r r i v e d A t R i d e O n S t o p   =   t r u e ; 
                         p e d e s t r i a n P t r . r e s e t ( ) ; 
 
                         i f   ( r o u t e P t r - > I s T r a n s f e r L i n e ( c u r r e n t S t o p N u m b e r ) )   { 
                                 c u r r e n t S t o p N u m b e r + + ; 
                         } 
 
                         c o n s t   S i m T i m e   c u r r e n t T i m e   =   r e s o u r c e . C u r r e n t T i m e ( ) ; 
 
                         s t o p A r r i v a l T i m e   =   c u r r e n t T i m e ; 
 
                         c o n s t   P u b l i c V e h i c l e R o u t e &   v e h i c l e R o u t e   = 
                                 r o u t e P t r - > p u b l i c V e h i c l e R o u t e s . a t ( c u r r e n t S t o p N u m b e r ) ; 
 
                         v e h i c l e S c h e d u l e A r r i v a l T i m e   = 
                                 t h e P u b l i c V e h i c l e T a b l e P t r - > G e t S c h e d u l e d A r r i v a l T i m e ( 
                                         v e h i c l e R o u t e . l i n e I d , 
                                         v e h i c l e R o u t e . r o u t e I d , 
                                         v e h i c l e R o u t e . v e h i c l e N u m b e r , 
                                         v e h i c l e R o u t e . o r i g S t o p I d , 
                                         c u r r e n t T i m e ) ; 
 
                         i f   ( ( * t h i s ) . M i s s e d P u b l i c V e h i c l e ( ) )   { 
 
                                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d o m N u m b e r G e n e r a t o r   =   r e s o u r c e . G e t R a n d o m N u m b e r G e n e r a t o r ( ) ; 
 
                                 i f   ( r a n d o m N u m b e r G e n e r a t o r . G e n e r a t e R a n d o m D o u b l e ( )   <   r e s o u r c e . M i s s e d V e h i c l e P a t h Q u e r y P r o b a b i l i t y ( ) )   { 
                                         r e s o u r c e . R e c a l c u l a t e R o u t e ( ) ; 
                                         r e s o u r c e . O u t p u t T r a c e ( " R o u t e   R e c a l c u l a t i o n   f o r   m i s s e d   a   v e h i c l e   a t   a r r i v e d   a t   t h e   s t o p . " ) ; 
                                 } 
                         } 
                 } 
         } 
 } 
 
 v o i d   P u b l i c V e h i c l e B e h a v i o r : : S e t P e d e s t r i a n B e h a v i o r T o w a r d N e x t S t o p ( 
         c o n s t   S t o p I d T y p e &   s t o p I d , 
         c o n s t   V e r t e x I d T y p e &   s t a r t V e r t e x I d , 
         c o n s t   V e r t e x I d T y p e &   d e s t V e r t e x I d ) 
 { 
         c o n s t   S i m T i m e   a r r i v a l T i m e M a r g i n   =   6 0 * S E C O N D ; 
 
         s h a r e d _ p t r < A g e n t R o u t e >   r o a d R o u t e P t r ( n e w   A g e n t R o u t e ( ) ) ; 
 
         t h e A g e n t G i s P t r - > S e a r c h R o a d R o u t e ( 
                 r e s o u r c e , 
                 s t a r t V e r t e x I d , 
                 d e s t V e r t e x I d , 
                 A G E N T _ B E H A V I O R _ P E D E S T R I A N , 
                 A G E N T _ B E H A V I O R _ P E D E S T R I A N , 
                 a r r i v a l T i m e M a r g i n , 
                 * r o a d R o u t e P t r ) ; 
 
         r e s o u r c e . O u t p u t T r a c e ( " W a l k T o S t o p   "   +   t h e P u b l i c V e h i c l e T a b l e P t r - > G e t S t o p N a m e ( s t o p I d )   +   "   "   +   r o a d R o u t e P t r - > C o n v e r t T o S t r i n g ( ) ) ; 
 
         p e d e s t r i a n P t r . r e s e t ( 
                 n e w   P e d e s t r i a n B e h a v i o r ( 
                         t h e A g e n t G i s P t r , 
                         t h e P u b l i c V e h i c l e T a b l e P t r , 
                         r o a d R o u t e P t r , 
                         t h e A g e n t G i s P t r - > G e t V e r t e x ( d e s t V e r t e x I d ) , 
                         r e s o u r c e ) ) ; 
 } 
 
 v o i d   P u b l i c V e h i c l e B e h a v i o r : : R i d e O n V e h i c l e I f P o s s i b l e ( ) 
 { 
         c o n s t   P u b l i c V e h i c l e R o u t e &   v e h i c l e R o u t e   = 
                 r o u t e P t r - > p u b l i c V e h i c l e R o u t e s . a t ( c u r r e n t S t o p N u m b e r ) ; 
 
         i f   ( t h e P u b l i c V e h i c l e T a b l e P t r - > I s S t a t i o n ( v e h i c l e R o u t e . o r i g S t o p I d ) )   { 
                 c o n s t   R a i l R o a d S t a t i o n I d T y p e &   s t a t i o n I d   = 
                         t h e P u b l i c V e h i c l e T a b l e P t r - > G e t S t a t i o n I d ( v e h i c l e R o u t e . o r i g S t o p I d ) ; 
 
                 c o n s t   A g e n t S t a t i o n &   s t a t i o n   =   t h e A g e n t G i s P t r - > G e t A g e n t S t a t i o n ( s t a t i o n I d ) ; 
 
                 v e h i c l e P t r   =   s t a t i o n . G e t T r a i n ( v e h i c l e R o u t e . l i n e I d ,   v e h i c l e R o u t e . r o u t e I d ,   g e t D o w n e d V e h i c l e I d s ,   r e s o u r c e ) ; 
 
         }   e l s e   { 
                 c o n s t   B u s S t o p I d T y p e &   b u s S t o p I d   = 
                         t h e P u b l i c V e h i c l e T a b l e P t r - > G e t B u s S t o p I d ( v e h i c l e R o u t e . o r i g S t o p I d ) ; 
 
                 c o n s t   A g e n t B u s S t o p &   b u s S t o p   =   t h e A g e n t G i s P t r - > G e t A g e n t B u s S t o p ( b u s S t o p I d ) ; 
 
                 v e h i c l e P t r   =   b u s S t o p . G e t B u s ( v e h i c l e R o u t e ,   g e t D o w n e d V e h i c l e I d s ,   r e s o u r c e ) ; 
         } 
 
         i f   ( v e h i c l e P t r   ! =   n u l l p t r )   { 
                 t h e A g e n t G i s P t r - > R i d e O n P u b l i c V e h i c l e ( r e s o u r c e ,   r e s o u r c e . C u r r e n t T i m e ( )   -   s t o p A r r i v a l T i m e ,   v e h i c l e P t r ) ; 
                 t r y R i d i n g   =   t r u e ; 
         } 
 
         r e s o u r c e . S e t P o s i t i o n ( r e s o u r c e . P o s i t i o n ( ) ) ; 
 } 
 
 v o i d   P u b l i c V e h i c l e B e h a v i o r : : D e c i d e P o s i t i o n I n V e h i c l e ( ) 
 { 
         H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d o m N u m b e r G e n e r a t o r   = 
                 r e s o u r c e . G e t R a n d o m N u m b e r G e n e r a t o r ( ) ; 
 
         c o n s t   P u b l i c V e h i c l e &   v e h i c l e   =   ( * v e h i c l e P t r ) ; 
         c o n s t   V e h i c l e F a m i l y &   v e h i c l e F a m i l y   =   v e h i c l e . G e t V e h i c l e F a m i l y ( ) ; 
 
         c o n s t   d o u b l e   r a n d o m P o s i t i o n I n V e h i c l e Y   = 
                 v e h i c l e F a m i l y . l e n g t h M e t e r s * r a n d o m N u m b e r G e n e r a t o r . G e n e r a t e R a n d o m D o u b l e ( )   - 
                 v e h i c l e F a m i l y . l e n g t h M e t e r s / 2 . ; 
 
         c o n s t   d o u b l e   r a n d o m P o s i t i o n I n V e h i c l e X   = 
                 v e h i c l e F a m i l y . w i d t h M e t e r s * r a n d o m N u m b e r G e n e r a t o r . G e n e r a t e R a n d o m D o u b l e ( )   - 
                 v e h i c l e F a m i l y . w i d t h M e t e r s / 2 . ; 
 
         c o n s t   V e r t e x   r a n d o m P o s i t i o n I n V e h i c l e ( 
                 r a n d o m P o s i t i o n I n V e h i c l e X , 
                 r a n d o m P o s i t i o n I n V e h i c l e Y ) ; 
 
         d e s t P o s i t i o n I n V e h i c l e M e t e r s   =   r a n d o m P o s i t i o n I n V e h i c l e . X Y D i s t a n c e ( ) ; 
 
         r e l a t i v e P o s i t i o n R a d i a n s   = 
                 r a n d o m P o s i t i o n I n V e h i c l e . D i r e c t i o n R a d i a n s ( ) ; 
 } 
 
 v o i d   P u b l i c V e h i c l e B e h a v i o r : : G e t D o w n V e h i c l e ( ) 
 { 
         i f   ( v e h i c l e P t r   ! =   n u l l p t r )   { 
                 c o n s t   P u b l i c V e h i c l e R o u t e &   v e h i c l e R o u t e   = 
                         r o u t e P t r - > p u b l i c V e h i c l e R o u t e s . a t ( c u r r e n t S t o p N u m b e r ) ; 
 
                 r e s o u r c e . S e t D e s i r e d N e x t P o s i t i o n I d ( v e h i c l e P t r - > G e t V i a P o i n t P o s i t i o n I d ( r e s o u r c e . C u r r e n t T i m e ( ) ) ) ; 
 
                 i f   ( v e h i c l e P t r - > C o n t a i n s ( r e s o u r c e ) )   { 
                         t h e A g e n t G i s P t r - > G e t D o w n P u b l i c V e h i c l e ( r e s o u r c e ,   v e h i c l e P t r ) ; 
                         g e t D o w n e d V e h i c l e I d s . i n s e r t ( v e h i c l e P t r - > G e t P u b l i c V e h i c l e I d ( ) ) ; 
                 } 
 
                 v e h i c l e P t r . r e s e t ( ) ; 
                 a r r i v e d A t R i d e O n S t o p   =   f a l s e ; 
 
                 c u r r e n t S t o p N u m b e r + + ; 
 
                 r e s o u r c e . R e m o v e O w n e r A g e n t ( ) ; 
         } 
 } 
 
 v o i d   P u b l i c V e h i c l e B e h a v i o r : : I n c r e m e n t T i m e S t e p I n V e h i c l e ( c o n s t   S i m T i m e &   t i m e S t e p ) 
 { 
         c o n s t   d o u b l e   w a l k D i s t a n c e M e t e r s   =   r e s o u r c e . W a l k S p e e d M e t e r s P e r S e c ( ) * d o u b l e ( t i m e S t e p ) / S E C O N D ; 
         c o n s t   S t o p I d T y p e &   g e t D o w n S t o p I d   =   r o u t e P t r - > G e t D o w n S t o p I d ( c u r r e n t S t o p N u m b e r ) ; 
 
         a n c h o r P o s i t i o n   =   v e h i c l e P t r - > G e t N e x t P o s i t i o n ( ) ; 
         a n c h o r D i r e c t i o n R a d i a n s   =   v e h i c l e P t r - > G e t N e x t D i r e c t i o n R a d i a n s ( ) ; 
 
         b o o l   m o v e I n V e h i c l e   =   f a l s e ; 
 
         i f   ( v e h i c l e P t r - > A t S t o p ( r e s o u r c e . C u r r e n t T i m e ( ) ) )   { 
 
                 c o n s t   S i m T i m e   c u r r e n t T i m e   =   r e s o u r c e . C u r r e n t T i m e ( ) ; 
                 c o n s t   V e r t e x I d T y p e   v e r t e x I d   =   v e h i c l e P t r - > G e t V i a P o i n t V e r t e x I d ( c u r r e n t T i m e ) ; 
 
                 r e s o u r c e . S e t V e r t e x I d ( v e r t e x I d ) ; 
 
                 i f   ( v e h i c l e P t r - > G e t S t o p I d ( )   = =   g e t D o w n S t o p I d )   { 
 
                         ( * t h i s ) . G e t D o w n V e h i c l e ( ) ; 
 
                 }   e l s e   i f   ( v e r t e x I d   = =   v i a P o i n t V e r t e x I d )   { 
 
                         ( * t h i s ) . F o r c e S t o p R i d i n g ( ) ; 
 
                 }   e l s e   { 
                         m o v e I n V e h i c l e   =   t r u e ; 
                 } 
         }   e l s e   { 
                 m o v e I n V e h i c l e   =   t r u e ; 
         } 
 
         i f   ( m o v e I n V e h i c l e )   { 
                 c u r r e n t P o s i t i o n I n V e h i c l e M e t e r s   =   s t d : : m i n ( 
                         d e s t P o s i t i o n I n V e h i c l e M e t e r s , 
                         c u r r e n t P o s i t i o n I n V e h i c l e M e t e r s   +   w a l k D i s t a n c e M e t e r s ) ; 
         } 
 
         ( * t h i s ) . U p d a t e A n c h o r P o s i t i o n ( ) ; 
 } 
 
 v o i d   P u b l i c V e h i c l e B e h a v i o r : : U p d a t e A n c h o r P o s i t i o n ( ) 
 { 
         c o n s t   d o u b l e   a b s P o s i t i o n R a d i a n s   = 
                 r e l a t i v e P o s i t i o n R a d i a n s   +   ( a n c h o r D i r e c t i o n R a d i a n s   -   P I / 2 . ) ; 
 
         c o n s t   V e r t e x   p o s i t i o n I n V e h i c l e ( 
                 c u r r e n t P o s i t i o n I n V e h i c l e M e t e r s   *   ( s t d : : c o s ( a b s P o s i t i o n R a d i a n s ) ) , 
                 c u r r e n t P o s i t i o n I n V e h i c l e M e t e r s   *   ( s t d : : s i n ( a b s P o s i t i o n R a d i a n s ) ) ) ; 
 
         r e s o u r c e . S e t P o s i t i o n ( a n c h o r P o s i t i o n   +   p o s i t i o n I n V e h i c l e ) ; 
 } 
 
 b o o l   P u b l i c V e h i c l e B e h a v i o r : : H a s F i n i s h e d ( )   c o n s t 
 { 
         r e t u r n   ( v e h i c l e P t r   = =   n u l l p t r   & & 
                         p e d e s t r i a n P t r   = =   n u l l p t r   & & 
                         c u r r e n t S t o p N u m b e r   > =   r o u t e P t r - > p u b l i c V e h i c l e R o u t e s . s i z e ( )   & & 
                         c u r r e n t P o s i t i o n I n V e h i c l e M e t e r s   = =   0 ) ; 
 } 
 
 v o i d   P u b l i c V e h i c l e B e h a v i o r : : F o r c e S t o p R i d i n g ( ) 
 { 
         ( * t h i s ) . G e t D o w n V e h i c l e ( ) ; 
 
         a r r i v e d A t R i d e O n S t o p   =   f a l s e ; 
         t r y R i d i n g   =   f a l s e ; 
 
         p e d e s t r i a n P t r . r e s e t ( ) ; 
         c u r r e n t S t o p N u m b e r   =   r o u t e P t r - > p u b l i c V e h i c l e R o u t e s . s i z e ( ) ; 
 } 
 
 b o o l   P u b l i c V e h i c l e B e h a v i o r : : I s O n P u b l i c V e h i c l e ( )   c o n s t 
 { 
         r e t u r n   ( v e h i c l e P t r   ! =   n u l l p t r ) ; 
 } 
 
 b o o l   P u b l i c V e h i c l e B e h a v i o r : : M i s s e d P u b l i c V e h i c l e ( )   c o n s t 
 { 
         c o n s t   P u b l i c V e h i c l e R o u t e &   v e h i c l e R o u t e   = 
                 r o u t e P t r - > p u b l i c V e h i c l e R o u t e s . a t ( c u r r e n t S t o p N u m b e r ) ; 
 
         i f   ( t h e P u b l i c V e h i c l e T a b l e P t r - > I s S t a t i o n ( v e h i c l e R o u t e . o r i g S t o p I d ) )   { 
                 c o n s t   R a i l R o a d S t a t i o n I d T y p e &   s t a t i o n I d   = 
                         t h e P u b l i c V e h i c l e T a b l e P t r - > G e t S t a t i o n I d ( v e h i c l e R o u t e . o r i g S t o p I d ) ; 
 
                 c o n s t   A g e n t S t a t i o n &   s t a t i o n   =   t h e A g e n t G i s P t r - > G e t A g e n t S t a t i o n ( s t a t i o n I d ) ; 
 
                 r e t u r n   s t a t i o n . H a s L e f t ( v e h i c l e R o u t e . l i n e I d ,   v e h i c l e R o u t e . r o u t e I d ,   v e h i c l e R o u t e . v e h i c l e N u m b e r ) ; 
 
         }   e l s e   { 
                 c o n s t   B u s S t o p I d T y p e &   b u s S t o p I d   = 
                         t h e P u b l i c V e h i c l e T a b l e P t r - > G e t B u s S t o p I d ( v e h i c l e R o u t e . o r i g S t o p I d ) ; 
 
                 c o n s t   A g e n t B u s S t o p &   b u s S t o p   =   t h e A g e n t G i s P t r - > G e t A g e n t B u s S t o p ( b u s S t o p I d ) ; 
 
                 r e t u r n   b u s S t o p . H a s L e f t ( v e h i c l e R o u t e . l i n e I d ,   v e h i c l e R o u t e . r o u t e I d ,   v e h i c l e R o u t e . v e h i c l e N u m b e r ) ; 
         } 
 } 
 
 v o i d   P u b l i c V e h i c l e B e h a v i o r : : E n d B e h a v i o r A t V i a P o i n t ( c o n s t   s h a r e d _ p t r < A g e n t R o u t e > &   n e x t R o u t e P t r ) 
 { 
         v i a P o i n t V e r t e x I d   =   ( * t h i s ) . G e t V i a P o i n t V e r t e x I d ( ) ; 
 } 
 
 V e r t e x I d T y p e   P u b l i c V e h i c l e B e h a v i o r : : G e t V i a P o i n t V e r t e x I d ( )   c o n s t 
 { 
         i f   ( ( * t h i s ) . I s O n P u b l i c V e h i c l e ( ) )   { 
 
                 r e t u r n   v e h i c l e P t r - > G e t V i a P o i n t V e r t e x I d ( r e s o u r c e . C u r r e n t T i m e ( ) ) ; 
 
         }   e l s e   i f   ( a r r i v e d A t R i d e O n S t o p )   { 
 
                 r e t u r n   r e s o u r c e . L a s t V e r t e x I d ( ) ; 
 
         }   e l s e   i f   ( p e d e s t r i a n P t r   ! =   n u l l p t r )   { 
 
                 r e t u r n   p e d e s t r i a n P t r - > G e t R o u t e ( ) . G e t D e s t V e r t e x I d ( ) ; 
         } 
 
         r e t u r n   r e s o u r c e . L a s t V e r t e x I d ( ) ; 
 } 
 
 b o o l   P u b l i c V e h i c l e B e h a v i o r : : I s A c c e p t a b l e R o u t e C h a n g e ( c o n s t   A g e n t R o u t e &   r o u t e )   c o n s t 
 { 
         r e t u r n   ( r o u t e . b e h a v i o r   = =   A G E N T _ B E H A V I O R _ B U S   | | 
                         r o u t e . b e h a v i o r   = =   A G E N T _ B E H A V I O R _ T R A I N ) ; 
 } 
 
 v o i d   P u b l i c V e h i c l e B e h a v i o r : : C h a n g e R o u t e ( c o n s t   s h a r e d _ p t r < A g e n t R o u t e > &   n e w R o u t e P t r ) 
 { 
         r o u t e P t r   =   n e w R o u t e P t r ; 
 
         c u r r e n t S t o p N u m b e r   =   0 ; 
         a r r i v e d A t R i d e O n S t o p   =   f a l s e ; 
         t r y R i d i n g   =   f a l s e ; 
 
         v i a P o i n t V e r t e x I d   =   I N V A L I D _ V E R T E X _ I D ; 
 } 
 
 } / / n a m e s p a c e   S c e n S i m 
 